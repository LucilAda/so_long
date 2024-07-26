/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:42:17 by lucilla           #+#    #+#             */
/*   Updated: 2024/07/26 15:13:05 by lufreder         ###   ########.fr       */
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
	{
		mlx_destroy_window(game->mlx_ptr, game->img_ptr);
		// mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		return (1);
	}
	game->img_ptr = mlx_new_image(game->mlx_ptr, game->width, game->height);
	if (!game->img_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		// mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		return (1);
	}
	place_images_in_game(game);
	graphics(game);
	mlx_key_hook(game->win_ptr, checking_controls, game);
	mlx_hook(game->win_ptr, 17, 0, (void *)exit, NULL);
	// event handling functions (key press or mouse move)
	mlx_loop(game->mlx_ptr);
	// continuously check for events and executes associated callbacks
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// to close window
	mlx_destroy_image(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->img_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	// to clean up the Minilibx connection
	return (0);
}
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }