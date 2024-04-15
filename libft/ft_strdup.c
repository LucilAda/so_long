/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:32:49 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/10 12:25:28 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (dest == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	char const	*s1 = "Hello ";
	char		*result;

	result = ft_strdup(s1);
	printf("%s", result);
	free (ft_strdup(s1));
	return (0);
}*/
