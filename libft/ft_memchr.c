/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:12:58 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/14 15:25:36 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	temp_char;
	size_t			i;

	str = (unsigned char *)s;
	temp_char = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == temp_char)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}

/*#include<stdio.h>

int	main(void)
{
	char	str[8] = "Accurate";
	char	c = 'u';
	size_t	size = 7;

	void *result = ft_memchr(str, c, size);
	
	if (result != NULL)
	printf("Le caractere '%c' a la position %ld.\n", c, (char *)result - str);
	else
	printf("Le caractere '%c' n'a pas ete trouve. \n", c);
	return (0);
}*/