/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:21:12 by lufreder          #+#    #+#             */
/*   Updated: 2024/07/18 15:01:31 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u(unsigned int nb, int *count)
{
	if (nb < 10)
		ft_putchar ((nb + 48), count);
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10, count);
		ft_putnbr_u(nb % 10, count);
	}
}
