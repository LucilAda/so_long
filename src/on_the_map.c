/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_the_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:07:07 by lucilla           #+#    #+#             */
/*   Updated: 2024/05/08 16:16:33 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < game->width)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	are_there_walls(t_game *map)
{
	int	walls;
	
	walls = check_walls(map);
	if (walls == 0)
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

int check_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	// if (game->map[height][width] != 'P' && game->map[height][width] != 'C'
	// && game->map[height][width] != 'E' && game->map[height][width] != 1 
	// && game->map[height][width] != 0 && game->map[height][width] != 1)
	// {
	// 	ft_printf("There is an error in this map\n");
	// 	return (0);
	// }
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E')
				game->numberE++;
			if (game->map[i][j] == 'P')
				game->numberP++;
			if (game->map[i][j] == 'C')
				game->numberC++;			
			j++;
		}
		i++;
	}
	ft_printf("In the end the number of exit is %i\n", game->numberE);
	ft_printf("In the end the number of player is %i\n", game->numberP);
	ft_printf("In the end the number of collectibles is %i\n", game->numberC);

	if (game->numberE != 1 || game->numberP != 1 || !(game->numberC >= 1))
	{
        ft_printf("Invalid number of exits, players, or collectibles in the map\n");
		return (0);
	}
    else
	{
        ft_printf("Map is valid, there are %i players %i exit %i collectibles\n", game->numberP, game->numberE, game->numberC);
		return (1);
	}
}