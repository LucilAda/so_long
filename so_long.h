/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:56:25 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/15 17:14:06 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG.H
# define SO_LONG.H

# include "./libft.h"
# include "./src/printf.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

#endif