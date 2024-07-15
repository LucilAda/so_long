/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:42:17 by lucilla           #+#    #+#             */
/*   Updated: 2024/06/27 16:15:03 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init(); // initialise X-window connection
	if (!game->mlx_ptr)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->width * 10),
			(game->height * 10), "So Long"); // create a new window
	if (!game->win_ptr)
		return (free(game->mlx_ptr), 1);
	game->img_ptr = mlx_new_image(game->mlx_ptr, game->width, game->height);
	if (!game->img_ptr)
		return (free(game->mlx_ptr), free(game->win_ptr), 1);
	place_images_in_game(game);
	graphics(game);
	mlx_key_hook(game->win_ptr, checking_controls, game);
	mlx_hook(game->win_ptr, 4, 0, (void *)exit, game);
	// event handling functions (key press or mouse move)
	mlx_loop(game->mlx_ptr);
	// continuously check for events and executes associated callbacks
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// to close window
	// mlx_destroy_image(game->mlx_ptr, game->win_ptr); 
	// to clean up the Minilibx connection
	return (0);
}
