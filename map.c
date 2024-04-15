/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:06:43 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/15 17:11:56 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_of_window(t_data *data, char *av[])
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error, invalid map\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
	{
		ft_printf
	}

}