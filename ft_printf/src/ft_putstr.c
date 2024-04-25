/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:21:29 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/25 16:27:39 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i])
		ft_putchar(str[i++], count);
}
