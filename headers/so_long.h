/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:56:25 by lufreder          #+#    #+#             */
/*   Updated: 2024/07/18 15:39:41 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define KEY_UP 'W'
# define KEY_RIGHT 'D'
# define KEY_LEFT 'A'
# define KEY_BOTTOM 'S'

typedef struct s_game
{
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		width;
	int		height;
	int		fd;
	void	*mlx;
	int		number_p;
	int		number_c;
	int		number_e;
	int		collectibles;
	int		reachable_collectibles;
	int		collected;
	int		coin;
	void	*win;
	int		window;
	int		visited;
	int		exit_found;
	char	**map;
	char	**map_copy;
	void	*img_ptr;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collectable;
}		t_game;

int 	map_read(t_game *game, char *av[]);
int		check_map_access(char *av[]);
bool	are_there_walls(t_game *map);
bool	are_pce_ok(t_game *game);
bool	check_requirements(t_game *game);
int		check_errors(t_game *game, char *av[]);
int		game_init(t_game *game);
int		checking_controls(int command, t_game *game);
void	graphics(t_game *game);
void	place_images_in_game(t_game *game);

#endif