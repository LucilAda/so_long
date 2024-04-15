/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:33:01 by lucilla           #+#    #+#             */
/*   Updated: 2024/04/04 11:31:36 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	len;
	char			*str;

	len = ft_digit_count(n);
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	if (nb == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nb != 0)
	{
		str[len -1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(-1800));
	return (0);
}*/