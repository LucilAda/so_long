/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:34:31 by lucilla           #+#    #+#             */
/*   Updated: 2024/08/02 14:40:39 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_errors(t_game *game, char *av[])
{
	if (check_map_access(&av[1]))
		ft_printf("Error .ber\n");
	if (!map_read(game, av[1]))
	{
		ft_printf("Can't read the map\n");
		return (1);
	}
	if (check_requirements(game) == false)
	{
		ft_printf("Looks like requirements are invalid\n");
		return (12);
	}
	return (0);
}
