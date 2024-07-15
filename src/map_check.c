/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:04 by lucilla           #+#    #+#             */
/*   Updated: 2024/06/27 16:06:52 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
/**
 * 
 * 1) Valider map (si validd => charger en mémoire (char **))
 *      - Valider longueur ligne (rectangle) - OK
 *      - Valider Player exist == 1 - OK
 *      - Valider Collectible >= 1 - OK
 *      - Valider Exit == 1 - OK
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

/**
 * Calculate the width of one line of the map
*/
static int	map_width(char *s)
{
	size_t	width;

	width = ft_strlen(s);
	if (s[width - 1] == '\n')
		width--;
	return (width);
}

/**
 * Add lines to the map
*/
static int	add_line(t_game *game, char *line)
{
	char	**tmp_map;
	int		i;

	i = 0;
	if (!line)
		return (0);
	game->height++;
	tmp_map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!tmp_map)
		return (0);
	tmp_map[game->height] = NULL;
	if (game->height > 1 && map_width(game->map[0]) != map_width(line))
		exit (1);
	while (i < game->height - 1)
	{
		tmp_map[i] = game->map[i];
		i++;
	}
	tmp_map[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp_map;
	return (2);
}

int	map_read(t_game *game, char *av[])
{
	char	*read_line;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd == -1)
	{
		ft_printf("Error opening fd %s\n", av[1]);
		return (0);
	}
	while (1)
	{
		read_line = get_next_line(game->fd);
		if (!add_line(game, read_line))
			break ;
	}
	game->width = map_width(game->map[0]);
	free(read_line);
	// close(game->fd);
	return (3);
}
/**
 * @brief ma fonction test si .ber 
 * @param
*/

//bool is_file_format_ok
int	check_map_access(char *av[])
{
	size_t	len;

	len = ft_strlen(av[1]);
	if (len < 4 || ft_strcmp(av[1] + len - 4, ".ber") != 0)
		return (ft_printf("Wrong type of file\n"));
	else
		return (ft_printf("The access of the map is correct\n"));
}
