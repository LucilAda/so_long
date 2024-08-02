/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_the_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:07:07 by lucilla           #+#    #+#             */
/*   Updated: 2024/08/02 16:34:30 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 * Create an array for the visited cells of the map
*/
int	**create_visited_array(int rows, int columns)
{
	int	i;
	int	**visited;

	visited = malloc(rows * sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		visited[i] = ft_calloc(columns, sizeof(int));
		i++;
	}
	return (visited);
}

char	*initialising_map_copy(t_game *game)
{
	int	i;

	game->map_copy = malloc(game->height * sizeof(char *));
	if (!game->map_copy)
		return ("Error allocation memory for the copy of the map\n");
	i = 0;
	while (i < game->height)
	{
		game->map_copy[i] = ft_strdup(game->map[i]);
		if (!game->map_copy[i])
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
		visited_cell[row][column] = true;
		return (false);
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
		return (false);
	if (are_pce_ok(game) == false)
		return (false);
	if (check_path_inside(game->height, game->width, visited_cell, game) == 1)
		return (false);
	while (i < game->height)
		free(visited_cell[i++]);
	free(visited_cell);
	return (true);
}
