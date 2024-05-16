/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:51:09 by lucilla           #+#    #+#             */
/*   Updated: 2024/05/15 17:04:50 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    init_struct(t_game *game)
{
	game->x = 0;
	game->y = 0;
    game->start_x = 0;
    game->start_y = 0;
	game->width = 0;
	game->height = 0;
	game->fd = 0;
    game->mlx = 0;
	game->numberP = 0;
	game->numberC = 0;
	game->numberE = 0;
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

int main(int ac, char *av[])
{
    t_game game;
    
    if (ac!= 2)
    {
        ft_printf("Usage: %s <map_file>\n", av[0]);
        return (1);
    }
    
    init_struct(&game);
    if(!check_map_access(av))
        ft_printf("Error .ber\n");
    if (!map_read(&game, av))
    {
        ft_printf("Error reading map\n");
        return (1);
    } 
    // Print the map to verify
    for (int i = 0; i < game.height; i++)
    {
        ft_printf("%s", game.map[i]);
    }
	ft_printf("\n");

    ft_printf("Before requirements are checked\n");
    if (check_requirements(&game) != 0)
    {
        ft_printf("check_requirements invalid\n");
        return (12);
    }
    ft_printf("After requirements are checked\n");

    for (int i = 0; i < game.height; i++)
    {
        ft_printf("%s", game.map[i]);
    }
    ft_printf("\n");
    
    free(game.map_copy);
    free(game.map);

    return 0;
}
    
    
    // mlx_init(); // initialise X-window connection
    // game->win = mlx_new_window(game->mlx; game->width * 32, game->height * 32, "So Long"); // create a new window
    // mlx_hook(game->win, 2, 0, key_press, game); // event handling functions (key press or mouse move)
    // mlx_hook(game->win, 17, 0, close_window, game);
    // mlx_loop(game->mlx); // continuously check for events and executes associated callbacks
    // mlx_pixel_put(); // provide window identifier, coordinates and color;
    // mlx_xpm_file_to_image(); // display image - load first
    // mlx_png_file_to_image(); // solution B to display image
    // mlx_destroy_window(); // to close window
    // mlx_destroy(); // to clean up the Minilibx connection
    
    // for (int y = 0; y < game->height; y++) 
    // {
    //     for (int x = 0; x < game->width; x++) 
    //     {
    //         int color;
    //         switch (game->map[y][x]) 
    //         {
    //             case '0': color = 0x000000; break; // empty space
    //             case '1': color = 0xffffff; break; // wall
    //             case 'P': color = 0x00ff00; break; // player
    //             case 'C': color = 0xffff00; break; // collectible
    //             case 'E': color = 0x0000ff; break; // exit
    //             default: color = 0x000000; break;
    //         }
    //         mlx_pixel_put(game->mlx, game->win, x * 32, y * 32, color);
    //     }
    // }
    
    // Don't forget to free the memory
    // for (int i = 0; i < game->height; i++)
    // {
    //     free(game->map[i]);
    // }