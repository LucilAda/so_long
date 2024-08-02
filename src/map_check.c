/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:04 by lucilla           #+#    #+#             */
/*   Updated: 2024/08/02 16:37:25 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/**
 * @brief ma fonction test si .ber 
 * @param
*/

int	check_map_access(char *av[])
{
	size_t	len;

	len = ft_strlen(av[1]);
	if (len < 4 || ft_strcmp(av[1] + len - 4, ".ber") != 0)
		return (0);
	else
	{
		ft_printf("access to map correct/n");
		return (1);
	}
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
	char	*read_line;

	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	game->map = NULL;
	game->height = 0;
	ft_printf("Hello to you from inside map read\n");
	while ((read_line = get_next_line(game->fd)) != NULL)
	{
		if (read_line == NULL)
		{
			ft_printf("Error reading line\n");
			break ;
		}
		if (!add_line(game, read_line))
		{
			ft_printf("Error adding line to map\n");
			free(read_line);
			break ;
		}
		free(read_line);
		game->height++;
	}
	if (game->map == NULL || game->map[0] == NULL)
	{
		ft_printf("Error reading map\n");
		close(game->fd);
		return (0);
	}
	game->width = map_width(game->map[0]);
	close(game->fd);
	return (1);
}

// int	map_read(t_game *game, char *file)
// {
// 	char	*read_line;

// 	game->fd = open(file, O_RDONLY);
// 	if (game->fd == -1)
	// {
	// 	ft_printf("Error opening fd %s\n", file);
	// 	return (0);
	// }
// 	while (1)
// 	{
// 		read_line = get_next_line(game->fd);
// 		if (!add_line(game, read_line))
// 			break ;
// 	}
// 	game->width = map_width(game->map[0]);
// 	free(read_line);
// 	close(game->fd);
// 	return (3);
// }