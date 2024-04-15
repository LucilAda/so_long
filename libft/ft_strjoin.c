/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:47:32 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/10 14:43:38 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		j++;
		i++;
	}
	dest[j] = 0;
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	char const	*s1 = "Hello ";
	char const	*s2 = "World";
	char		*result;

	result = ft_strjoin(s1, s2);
	printf("%s", result);
	return (0);
}
*/