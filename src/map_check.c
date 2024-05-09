/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:04 by lucilla           #+#    #+#             */
/*   Updated: 2024/05/08 16:58:03 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/**
 * 
 * 1) Valider map (si validd => charger en mémoire (char **))
 *      - Valider longueur ligne (rectangle)
 *      - Valider Player exist == 1
 *      - Valider Collectible >= 1
 *      - Valider Exit == 1
 *      - Valider Chemin possible
 * Flood fill?
 *      - Valider Charactères invalid (P/M/C/E/W)
 * If (letter != 'P' || letter != 'C' || letter != 'E' || letter != 'W')
 *      - Valider que la map c'est ".ber"
 * check ft_strnstr(path == ".ber")
 * 2) Charger les textures
 * 3) Préparer la minilibx
 * 4) Start la mlx_loop();
 * 5) Game logic
 *      - Input Keyboard (W/A/S/D + esc)
 *      - pouvoir Quitter (croix rouge)
 *      - pouvoir gagner
 *          - ramasser les collectibles
 *          - gérer collision exit
 *          - imprimer le nombre de mouvement (dans le terminal)
*/

static int	map_width(char *s)
{
	size_t	width;
	
	width = ft_strlen(s);
	if (s[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**tmp;
	int		i;
	
	i = 0;
	if (!line)
		return (0);
	game->height++;
	tmp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!tmp)
		return (0);
	tmp[game->height] = NULL;
	while (i < game->height - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

int map_read(t_game *game, char *av[])
{
	char	*reading;
	game->fd = open(av[1], O_RDONLY);
	if (game->fd == -1)
	{
		ft_printf("Error opening fd %s\n", av[1]);
		return (0);
	}
	while (1)
	{
		reading = get_next_line(game->fd);
		if (!reading)
			ft_printf("error reading\n");
		if (!add_line(game, reading))
			break;
	}
	game->width = map_width(game->map[0]);
	free(reading);
	close(game->fd);
	return (1);
}

int	check_map_access(char *av[])
{
	size_t len;
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strcmp(av[1] + len - 4, ".ber") != 0) 
	{
		ft_printf("Wrong type of file\n");
		return (EXIT_FAILURE);
	}
	ft_printf("The access of the map is correct\n");
	return (EXIT_SUCCESS);
}
