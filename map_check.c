/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:04 by lucilla           #+#    #+#             */
/*   Updated: 2024/05/03 17:37:46 by lucilla          ###   ########.fr       */
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
	int	width;
	
	width = 0;
	while(s[width])
	{
		width++;
	}
	if (s[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *m, char *line)
{
	char	**tmp;
	int		i;
	
	i = 0;
	if (!line)
		return (0);
	m->height++;
	tmp = (char **)malloc(sizeof(char *) * (m->height + 1));
	if (!tmp)
		return (0);
	tmp[m->height] = NULL;
	while (i < m->height - 1)
	{
		tmp[i] = m->map[i];
		i++;
	}
	tmp[i] = line;
	if (m->map)
		free(m->map);
	m->map = tmp;
	return (1);
}
int map_read(t_game *m, char *av[])
{
	char	*reading;
	m->fd = open(av[1], O_RDONLY);
	if (!m->fd)
	{
		ft_printf("Error opening fd");
		return (0);
	}
	while (1)
	{
		reading = get_next_line(m->fd);
		if (!add_line(m, reading))
			break;
	}
	close(m->fd);
	m->width = map_width(m->map[0]);
	return (1);
}

void check_collectibles(t_game playground)
{
    int i;
    int j;

	i = 0;
	playground.numberE = 0;
	playground.numberP = 0;
	playground.numberC = 0;
    while (i < playground.height)
    {
		j = 0;
        while (j < playground.width)
        {
            if (playground.map[i][j] != 'P' && playground.map[i][j] != 'C'
			&& playground.map[i][j] != 'E' && playground.map[i][j] != 1 
			&& playground.map[i][j] != 0)
			{
                ft_printf("There is an error in this map");
				return ;
			}
			j++;
        }
		i++;
		if (playground.map[i][j] == 'E')
			playground.numberE++;
		if (playground.map[i][j] == 'P')
			playground.numberP++;
		if (playground.map[i][j] == 'C')
			playground.numberC++;
    }
	if (playground.numberE != 1 || playground.numberP != 1 || playground.numberC < 1)
        ft_printf("Invalid number of exits, players, or collectibles in the map\n");
    else
        ft_printf("Map is valid\n");
}

int main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		printf("Usage: %s <map_file>\n", av[0]);
		return 1;
	}
	map_read(&game, av);

	// Print the contents of the t_map structure
	printf("Map dimensions:\n");
	printf("Width: %d\n", game.width);
	printf("Height: %d\n", game.height);

	printf("Map contents:\n");
	for (int i = 0; i < game.height; i++)
	{
		printf("%s", game.map[i]);
	}

	// Free allocated memory
	for (int i = 0; i < game.height; i++)
	{
		free(game.map[i]);
	}
	free(game.map);

	return 0;
}