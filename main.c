/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:58:44 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/15 16:58:59 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include <stdlib.h>
 
int main(void)
{
	void *mlx_ptr;
 
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	free(mlx_ptr);
	return (0);
}