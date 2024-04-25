/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_xup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:21:03 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/25 16:26:50 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_hex_xup(unsigned int nb, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putnbr_hex_xup(nb / 16, count);
	ft_putchar(base[nb % 16], count);
}
