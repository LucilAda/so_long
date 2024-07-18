/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:21:23 by lufreder          #+#    #+#             */
/*   Updated: 2024/07/18 15:01:36 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_putstr("0x", count);
	ft_putnbr_hex_ptr(addr, count);
}
