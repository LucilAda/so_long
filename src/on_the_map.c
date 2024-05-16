/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_the_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:07:07 by lucilla           #+#    #+#             */
/*   Updated: 2024/05/16 08:26:51 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../headers/so_long.h"

int	check_walls(t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (row < game->height)
	{
		if (game->map[row][0] != '1' || game->map[row][game->width - 1] != '1')
			return (0);
		row++;
	}
	column = 0;
	while (column < game->width)
	{
		if (game->map[0][column] != '1' 
			|| game->map[game->height - 1][column] != '1')
			return (0);
		column++;
	}
	return (1);
}

int	are_there_walls(t_game *map)
{
	if (!check_walls(map))
	{
		ft_printf("This map is missing some walls\n");
		return (EXIT_FAILURE);
	}
	else
	{
		ft_printf("This map have all walls needed\n");
		return (1);
	}
}

static void count_collectibles(t_game *game, int row, int column)
{
	if (game->map[row][column] != 'P' && game->map[row][column] != 'C'
	&& game->map[row][column] != 'E'&& game->map[row][column] != '0'
	&& game->map[row][column] != '1' && game->map[row][column] != '\n')
	{
		ft_printf("There is an error in this map\n");
		return ;
	}
	if (game->map[row][column] == 'E')
		game->numberE++;
	else if (game->map[row][column] == 'P')
		game->numberP++;
	else if (game->map[row][column] == 'C')
		game->numberC++;
}

void	check_collectibles_correct(t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (row < game->height - 1)
	{
		column = 0;
		while (column < game->width)
		{
			count_collectibles(game, row, column);
			column++;
		}
		row++;
	}
	if (game->numberE != 1 || game->numberP != 1 || game->numberC < 1)
	{
		ft_printf("Number of player, exit or collectibles incorrect\n");
	}
	else
	{
		ft_printf("Number of player, exit and collectibles correct\n");
	}
}

/**
 * Checking the inside of the map and using a copy of the map 
 * to change the visited_cell to 1 once visited
 * First check if we are not outside the map
 * Then if the cell we are on is an E, it is the exit
 * It is an C we increase the number of collectibles found
 * SEGMENTATION FAULT BECAUSE OF THE MAP_COPY ALLOCATION OF MEMORY
*/
/*
 * Create an array for the visited cells of the map
*/
int **create_visited_array(int rows, int columns)
{
    int i;
    int **visited;
    
    visited = malloc(rows * sizeof(int *));
    if (!visited)
		return NULL; 
    i = 0;
    while(i < rows)
    {
        visited[i] = ft_calloc(columns, sizeof(int));
        i++;
    }
    return (visited);
}
/**
 * Check the path to access the whole game map
*/
int flood_check(t_game *game, int x, int y, int **visited)
{
    if (x < 0 || x >= game->width || y < 0 || y >= game->height) 
        return (0); // check if we are not out of the map
    if (game->map[y][x] == '1' || visited[y][x]) 
        return (0); 
    visited[y][x] = 1;
    if (game->map[y][x] == 'C')
        game->reachable_collectibles++;
    if (game->map[y][x] == 'E')
        game->exit_found = 1;
    if (game->reachable_collectibles == game->numberC && game->exit_found)
        return (1);
    if (flood_check(game, x + 1, y, visited) ||
        flood_check(game, x - 1, y, visited) ||
        flood_check(game, x, y + 1, visited) ||
        flood_check(game, x, y - 1, visited))
        return (1);
    return (0);
}

int check_access(t_game *game)
{
    int **visited;
    int exit_is_reachable;

	visited = create_visited_array(game->height, game->width);
	exit_is_reachable = flood_check(game, game->start_x, game->start_y, visited);
    game->reachable_collectibles = 0; 
    // if (!visited) 
    //     return(ft_printf(MEM_ERR));
	ft_printf("number of collectibes is %i\n", game->reachable_collectibles);
    if (!(game->reachable_collectibles == game->numberC && exit_is_reachable))
    {
        // free_resources(NULL, NULL, visited, game->height);
        return(ft_printf("Exit now\n"));
    }
    // free_resources(NULL, NULL, visited, game->height);
    // game->reachable_collectibles = 0;
    return (0);
}
/**
 * @brief avec une copie de map,
 * tu remplies avec "P" tant que move valid (up down left right)
 * ensuite check si tous les C et E ont été recouverts
*/

int	check_path_inside(int row, int column, int **visited_cell, t_game *game)
{
	// create copy map
	int i;
	
	game->map_copy = malloc(game->height * sizeof(char *));
	if(!game->map_copy)
		return(0);
	i = 0;
	while(i < game->height)
	{
		game->map_copy[i] = ft_strdup(game->map[i]);
		//if(!game->map_copy[i])
		//	return(free_previous(i, game->map_copy));
		i++;
	}
	if (row >= game->height || row < 0 || column >= game->width || column < 0)
		return (0);
	ft_printf("Visiting cell (%d, %d)\n", row, column);
	if (game->map[row][column] == 'E')
	{
		ft_printf("Found the exit\n");
		return (ft_printf("I found the exit\n"));
	}
	if (visited_cell[row][column] == '1' || visited_cell[row][column])
		return (0);
	// if (game->map[row][column] == 'C')
	// {
	// 	game->collectibles++;
	// }
	visited_cell[row][column] = true;
	game->map_copy[row][column] = 'P';
	if (check_path_inside(row, column + 1, visited_cell, game)
		|| check_path_inside(row, column - 1, visited_cell, game)
		|| check_path_inside(row + 1, column, visited_cell, game)
		|| check_path_inside(row - 1, column, visited_cell, game))
			return (1);
	return (0);
}

int	check_requirements(t_game *game)
{
	int	**visited_cell;
	visited_cell = create_visited_array(game->height, game->width);
    if (are_there_walls(game) != 1)
		exit(EXIT_FAILURE);
    check_collectibles_correct(game);
	
	flood_check(game, game->x, game->y, visited_cell);
	//check_access(game);
	// check_path_inside(game->height, game->width, visited_cell, game);
	int i;
	i = 0;
	while(i < game->height)
		free(visited_cell[i++]);
	free(visited_cell);
	return (1);
}