/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:27:29 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/07 11:23:21 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *) haystack + i);
		}
		i++;
	}
	j = 0;
	return (0);
}

/*#include<stdio.h>

int main(void)
{
	char	c[] = "Botte de foin";
	char	s[20] = "foin";
	size_t	n = 40;

	char *result = ft_strnstr(s, c, n);

	if (result != NULL)
		printf("Chaine trouvee : %s\n", result);
	else
		printf("chaine non trouvee\n");
	return (0);
}*/