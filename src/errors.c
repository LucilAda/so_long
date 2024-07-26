/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:34:31 by lucilla           #+#    #+#             */
/*   Updated: 2024/07/25 15:58:06 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_errors(t_game *game, char *av[])
{
	if (!map_read(game, av[1]))
	{
		ft_printf("Error reading map\n");
		return (1);
	}
	if (check_requirements(game) == false)
	{
		ft_printf("check_requirements invalid\n");
		return (12);
	}
	if (!check_map_access(av[1]))
		ft_printf("Error .ber\n");
	return (0);
}
