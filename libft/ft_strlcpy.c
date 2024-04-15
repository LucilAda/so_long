/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:23:05 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/04 11:33:45 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t			i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size < 1)
		return (src_len);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*#include<stdio.h>

int	main(void)
{
	char	dest[] = "Arbre ";
	char	src[] = "Serpent a sonette";
	printf("premiere %zu %s\n", ft_strlcpy(dest, src, 78), dest);
	
	char	dd[] = "Hello bonjour";
	char	hu[] = "Tu e";
	printf("deuxieme %zu %s\n", ft_strlcpy(dd, hu, 12), dd);
	return (0);	
}
*/