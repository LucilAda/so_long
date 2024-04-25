/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_xlo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:20:57 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/25 16:26:48 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_hex_xlo(unsigned int nb, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_putnbr_hex_xlo(nb / 16, count);
	ft_putchar(base[nb % 16], count);
}
