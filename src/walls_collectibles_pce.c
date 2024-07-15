/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_collectibles_pce.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:23:00 by lucilla           #+#    #+#             */
/*   Updated: 2024/06/27 14:23:29 by lucilla          ###   ########.fr       */
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

static void	count_collectibles(t_game *game, int row, int column)
{
	char	cell;

	cell = game->map[row][column];
	if (cell != 'P' && cell != 'C' && cell != 'E' && cell != '0'
		&& cell != '1' && cell != '\n')
	{
		ft_printf("There is an error in this map\n");
		return ;
	}
	if (cell == 'E')
		game->number_e++;
	else if (cell == 'P')
		game->number_p++;
	else if (cell == 'C')
		game->number_c++;
}

/**
 * Check if there is the correct amount of players, exit, and collectibles
*/
bool	are_pce_ok(t_game *game)
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
	if (game->number_e != 1 || game->number_p != 1 || game->number_c < 1)
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
