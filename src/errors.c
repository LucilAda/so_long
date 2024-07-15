/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:34:31 by lucilla           #+#    #+#             */
/*   Updated: 2024/06/27 10:28:30 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_errors(t_game *game, char *av[])
{
	if (!map_read(game, av))
	{
		ft_printf("Error reading map\n");
		return (1);
	}
	if (check_requirements(game) == false)
	{
		ft_printf("check_requirements invalid\n");
		return (12);
	}
	if (!check_map_access(av))
		ft_printf("Error .ber\n");
	return (0);
}
