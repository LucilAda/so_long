/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:08:23 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/10 14:38:59 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dest = (char *)malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include<stdio.h>
#include<stdlib.h>
int	main(void)
{
	char	s[] = " ";
	size_t	start = 0;
	size_t	len = 0;

	char	*result = ft_substr(s, start, len);

	printf("Resultat : %s\n", result);
	free(result);
	return (0);
}*/