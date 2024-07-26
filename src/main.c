/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:51:09 by lucilla           #+#    #+#             */
/*   Updated: 2024/07/26 14:15:47 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	init_struct(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->start_x = 0;
	game->start_y = 0;
	game->width = 0;
	game->height = 0;
	game->fd = 0;
	game->number_p = 0;
	game->number_c = 0;
	game->number_e = 0;
	game->collectibles = 0;
	game->reachable_collectibles = 0;
	game->collected = 0;
	game->coin = 0;
	game->visited = 0;
	game->map = NULL;
	game->map_copy = NULL;
	game->window = 0;
	game->exit_found = 0;
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Usage: %s <map_file>\n", av[0]);
		return (1);
	}
	init_struct(&game);
	if (!check_map_access(av[1]))
	{
		ft_printf("Error .ber\n");
		return (1);
	}
	
	if (!map_read(&game, av[1]))
	{
		ft_printf("Error reading map\n");
		return (1);
	}
	
	if (check_requirements(&game) == false)
	{
		ft_printf("requirements not met\n");
		return (1);
	}
	
	if (check_errors(&game, &av[1]) == 0)
	{
		ft_printf("All good!\n");
		return (1);
	}
	
	game_init(&game);
	free(game.map_copy);
	free(game.map);
	return (0);
}

	// Don't forget to free the memory
	// for (int i = 0; i < game->height; i++)
	// {
	//     free(game->map[i]);
	// }
	// Print the map to verify
	// for (int i = 0; i < game.height; i++)
	// {
	//     ft_printf("%s", game.map[i]);
	// }
	// ft_printf("\n");