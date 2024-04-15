/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:07:42 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/04 11:26:55 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

/*#include<stdio.h>
#include<string.h>

int main(void)
{
	char	s[] = "Hello";
	char	*ptr = ft_strchr(s, 'e');
	printf("Le caractère a été trouvé à la position %ld\n", ptr - s);
	
	return (0);
}*/
