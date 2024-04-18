/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:06:43 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/18 16:52:23 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"


typedef struct s_long
{
	int		fd;
	int		height_map;
	int		width_map;

	char	**map;
}	t_long;

static int	width_of_map(char *s)
{
	int	width;

	width = 0;
	while(s[width] != '\0')
		width++;
	if (s[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_long *game, char	*av[])
{
	char	*readmap;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while(1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break;
	}
	close (game->fd);
	game->width_map = width_of_map(game->map[0]);
	return (1);
}
