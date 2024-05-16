/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:56:25 by lufreder          #+#    #+#             */
/*   Updated: 2024/05/10 11:49:59 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "./get_next_line.h"
// # include "../minilibx/mlx.h"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>


#define KEY_UP 'W'
#define KEY_RIGHT 'D'
#define KEY_LEFT 'A'
#define KEY_BOTTOM 'S'



// typedef struct s_data
// {
// 	void		*mlx_ptr; // MLX pointer
// 	void		*win_ptr; // MLX window pointer
// 	void		*textures[5]; // MLX image pointers (on the stack)
// 	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
// }	t_data;

typedef struct s_game
{
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		width;
	int		height;
	int		fd;
	int		mlx;
	int		numberP;
	int		numberC;
	int		numberE;
	int		collectibles;
	int		reachable_collectibles;
	int		collected;
	int		coin;
	int		win;
	int		window;
	int		visited;
	int		exit_found;
	char	**map;
	char	**map_copy;
}		t_game;

int 	map_read(t_game *game, char *av[]);
int		check_map_access(char *av[]);
int		are_there_walls(t_game *map);
void	check_collectibles_correct(t_game *game);
int		check_requirements(t_game *game);


#endif