/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:56:25 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/18 16:48:03 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG.H
# define SO_LONG.H

# include "./libft.h"
# include "./printf.h"
# include "./get_next_line.h"
# include "../minilibx/mlx.h"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>


#define KEY_UP 'W'
#define KEY_RIGHT 'D'
#define KEY_LEFT 'A'
#define KEY_BOTTOM 'S'

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;


typedef struct {
	int	x;
	int	y;
} t_player;

typedef struct s_vars
{
	t_player	*player;
} 	t_vars;

typedef struct s_long
{
	int		fd;
	int		height_map;
	int		width_map;

	char	**map;
}	t_long;

#endif