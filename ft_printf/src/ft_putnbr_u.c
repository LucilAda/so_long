/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:21:12 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/25 16:26:52 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
