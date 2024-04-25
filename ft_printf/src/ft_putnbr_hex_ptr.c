/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:20:51 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/25 16:26:46 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_hex_ptr(unsigned long nbr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbr_hex_ptr(nbr / 16, count);
	ft_putchar(base[nbr % 16], count);
}
