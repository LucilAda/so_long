/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:04 by lucilla           #+#    #+#             */
/*   Updated: 2024/07/26 15:13:32 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/**
 * @brief ma fonction test si .ber 
 * @param
*/

int	check_map_access(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strcmp(file + len - 4, ".ber") != 0)
	{	
		return (ft_printf("Wrong type of file\n"));
		return (0);
	}
	else
		return (ft_printf("The access of the map is correct\n"));
}

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
	if (game->map != NULL)
		free(game->map);
	game->map = tmp_map;
	return (2);
}

/**
 * Open and read the content of the map
*/
int	map_read(t_game *game, char *file)
{
    char *read_line;
    game->fd = open(file, O_RDONLY);
    if (game->fd < 0) {
        ft_printf("Error opening file\n");
        return (0);
    }
    game->map = NULL;
    game->height = 0;
    while ((read_line = get_next_line(game->fd)) != NULL) 
	{
        if (!add_line(game, read_line)) 
		{
            free(read_line);
            break;
        }
        free(read_line);
    }
    close(game->fd);
    if (game->map == NULL || game->map[0] == NULL) 
	{
        ft_printf("Error reading map\n");
        return (0);
    }
    game->width = map_width(game->map[0]);

    return (3);
}
