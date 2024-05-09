/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:51:09 by lucilla           #+#    #+#             */
/*   Updated: 2024/05/08 16:35:21 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    init_struct(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->width = 0;
	game->height = 0;
	game->fd = 0;
	game->numberP = 0;
	game->numberC = 0;
	game->numberE = 0;
	game->map = NULL;
}

int main(int ac, char *av[])
{
    t_game *game;
    
    if (ac!= 2)
    {
        ft_printf("Usage: %s <map_file>\n", av[0]);
        return (1);
    }
    game = malloc(sizeof(t_game));
    if (!game)
        return 0;
    init_struct(game);
    if (!map_read(game, av))
    {
        ft_printf("Error reading map\n");
        return (1);
    }
    // Print the map to verify
    for (int i = 0; i < game->height; i++)
    {
        ft_printf("%s", game->map[i]);
    }
	ft_printf("\n");

    check_map_access(av);
    // are_there_walls(game);
    // check_collectibles(game);
    
    // // Don't forget to free the memory
    // for (int i = 0; i < game->height; i++)
    // {
    //     free(game->map[i]);
    // }
    // free(game->map);

    return 0;
}