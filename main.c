/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:58:44 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/18 16:52:56 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mlx/mlx.h"
// #include "so_long.h"
// #include <stdlib.h>
 
// int main(void)
// {
// 	void *mlx_ptr;
 
// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (1);
// 	free(mlx_ptr);
// 	return (0);
// }
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	t_long	game;

	if(ac != 2)
		return (0);
	if (map_reading(&game, av) == 1)
		printf("The map is correct");
	return (0);
}