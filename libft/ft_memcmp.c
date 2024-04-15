/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:12:13 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/08 14:52:25 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*#include<stdio.h>

int	main(void)
{
	unsigned char	str1[] = "Les harengs";
	unsigned char	str2[] = "Les parents";
	size_t n = 6;

	int result = ft_memcmp(str1, str2, n);
	if (result == 0)
		printf("Ces deux chaines sont identiques.\n");
	else
		printf("La différence entre ces chaines est de: %d.\n", result);
	return (0);
}*/