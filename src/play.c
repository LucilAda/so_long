/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:49:21 by lucilla           #+#    #+#             */
/*   Updated: 2024/08/02 16:33:52 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	while (line < game->height - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

static int	right_move(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectibles != 0)
			return (0);
		ft_printf("\nYou Have Won, Congrats!\n");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->visited++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->collectibles--;
		game->visited++;
	}
	return (1);
}

static int	keyboard_w_s(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x;
	j = game->y;
	if (movement == KEY_UP)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == KEY_BOTTOM)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->visited);
	ft_printf("Collectables Left: %i\n", game->collectibles);
	return (1);
}

static int	keyboard_a_d(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x;
	j = game->y;
	if (movement == KEY_LEFT)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == KEY_RIGHT)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->visited);
	ft_printf("Collectables Remaining: %i\n", game->collectibles);
	return (1);
}

int	checking_controls(int command, t_game *game)
{
	int	works;

	if (command == 53)
		exit_point(game);
	if (command == 13)
		works = keyboard_w_s(game, command);
	if (command == 1)
		works = keyboard_w_s(game, command);
	if (command == 0)
		works = keyboard_a_d(game, command);
	if (command == 2)
		works = keyboard_a_d(game, command);
	if (works)
		graphics(game);
	return (1);
}

// for (int y = 0; y < game.height; y++)
// {
//     for (int x = 0; x < game.width; x++)
//     {
//         int color;
//         switch (game.map[y][x])
//         {
//             case '0': color = 0x000000; break; // empty space
//             case '1': color = 0xffffff; break; // wall
//             case 'P': color = 0x00ff00; break; // player
//             case 'C': color = 0xffff00; break; // collectible
//             case 'E': color = 0x0000ff; break; // exit
//             default: color = 0x000000; break;
//         }
//         mlx_pixel_put(game.mlx, game.win, x * 32, y * 32, color);
//     }
// }