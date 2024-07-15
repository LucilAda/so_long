/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:54:51 by lufreder          #+#    #+#             */
/*   Updated: 2024/06/27 16:13:15 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->player, width * 10, height * 10);
	game->y = height;
	game->x = width;
}

void	place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->collectable, width * 10, height * 10);
	game->collectibles++;
}

void	place_images_in_game(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/item.xpm", &i, &j);
}

void	draw_map(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->wall, width * 10, height * 10);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->floor, width * 10, height * 10);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->exit, width * 10, height * 10);
			width++;
		}
		height++;
	}
}

void	graphics(t_game *game)
{
	game->collectable = 0;
	draw_map(game);
	int height;
	int	width;

	height = 0;
	width = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			width++;
		}
		height++;
	}
}
