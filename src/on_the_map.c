/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_the_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:07:07 by lucilla           #+#    #+#             */
/*   Updated: 2024/05/21 11:57:54 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

bool	are_there_walls(t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (row < game->height)
	{
		if (game->map[row][0] != '1' || game->map[row][game->width - 1] != '1')
			return (false);
		row++;
	}
	column = 0;
	while (column < game->width)
	{
		if (game->map[0][column] != '1' 
			|| game->map[game->height - 1][column] != '1')
				return (false);
			column++;
	}
	return (true);
}

static void count_collectibles(t_game *game, int row, int column)
{
	char cell = game->map[row][column];
	
	if (cell != 'P' && cell != 'C'&& cell != 'E' && cell != '0'
		&& cell != '1' && cell != '\n')
		{
			ft_printf("There is an error in this map\n");
			return ;
		}
	if (cell == 'E')
		game->numberE++;
	else if (cell == 'P')
		game->numberP++;
	else if (cell == 'C')
		game->numberC++;
}

/**
 * Check if there is the correct amount of players, exit, and collectibles
*/
bool	are_PCE_ok(t_game *game)
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
		return (false);
	}
	else
	{
		ft_printf("Number of player, exit and collectibles correct\n");
		return (true);
	}
}

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
 * With a copy of the map, fill in the 0 with P
 * as long as moves are valid (up down left right)
 * then checks if C and E have been covered
*/

// bool	is_there_a_path(int row, int column, int **visited_cell, t_game *game)
// {
// 	int i;
	
// 	game->map_copy = malloc(game->height * sizeof(char *));
// 	if(!game->map_copy)
// 		return(false);
// 	i = 0;
// 	while(i < game->height) //creating a copy of the map
// 	{
// 		game->map_copy[i] = ft_strdup(game->map[i]);
// 		if(!game->map_copy[i])
// 		{
// 			free(game->map_copy);
// 			return(false);
// 		}
// 		i++;
// 	}
// 	if (row >= game->height - 1 || row < 0 || column >= game->width - 1 || column < 0)
// 			return (false);
			
// 	ft_printf("I'm here in the is_there_path\n");
// 	if (game->map[row][column] == 'E')
// 	{
// 		ft_printf("Found the exit\n");
// 		return (true);
// 	}
// 	ft_printf("Visiting cell (%d, %d)\n", row, column);
// 	if (visited_cell[row][column] == '1' || visited_cell[row][column])
// 		return (false);
// 	// if (game->map[row][column] == 'C')
// 	// {
// 	// 	game->collectibles++;
// 	// }
// 	visited_cell[row][column] = true;
// 	game->map_copy[row][column] = 'P';
// 	if (is_there_a_path(row, column + 1, visited_cell, game)
// 		|| is_there_a_path(row, column - 1, visited_cell, game)
// 		|| is_there_a_path(row + 1, column, visited_cell, game)
// 		|| is_there_a_path(row - 1, column, visited_cell, game))
// 			return (true);
// 	return (true);
// }
char	*initialising_map_copy(t_game *game)
{
	int	i;
	game->map_copy = malloc(game->height * sizeof(char *));
	if(!game->map_copy)
		return("Error allocation memory for the copy of the map\n");
	i = 0;
	while(i < game->height)
	{
		game->map_copy[i] = ft_strdup(game->map[i]);
		if(!game->map_copy[i])
		{
			ft_printf("Error copying the map\n");
			free(game->map_copy);
		}
		i++;
	}
	return (*game->map_copy);
}
int	check_path_inside(int row, int column, int **visited_cell, t_game *game)
{	
	*game->map_copy = initialising_map_copy(game);
	if (row >= game->height || row < 0 || column >= game->width || column < 0)
		return (false);
	if (game->map[row][column] == 'C')
	{
		game->collectibles++;
		return (true);	
	}
	if (game->map[row][column] == '1' || visited_cell[row][column])
	{
		return (false);
		visited_cell[row][column] = true;
	}
	game->map_copy[row][column] = 'P';
	if (check_path_inside(row, column + 1, visited_cell, game)
		|| check_path_inside(row, column - 1, visited_cell, game)
		|| check_path_inside(row + 1, column, visited_cell, game)
		|| check_path_inside(row - 1, column, visited_cell, game))
			return (true);
	return (false);
}

bool	check_requirements(t_game *game)
{
	int	**visited_cell;
	int	i;
	
	visited_cell = create_visited_array(game->height, game->width);
	i = 0;
	
    if (are_there_walls(game) == false)
		exit(false);
		
    if (are_PCE_ok(game) == false)
		exit(false);
	// if (is_there_a_path(game->height, game->width, visited_cell, game) == false)
	// 	exit(false);
	if (check_path_inside(game->height, game->width, visited_cell, game) == 1)
		exit(false);
	ft_printf("I'm after the path has been checked\n");
		
	while(i < game->height)
		free(visited_cell[i++]);
	free(visited_cell);
	return (true);
}