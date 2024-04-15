/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:59:58 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/07 12:08:03 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	dest = (char *)malloc((end - start + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (start < end)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	char	string[] = "ababVive la Suisseabbbab";
	char	*ctofind = "ab";

	char	*trimmedstring = ft_strtrim(string, ctofind);
	
	if (trimmedstring)
	{
		printf("La phrase trimée est: %s\n", trimmedstring);
		free(trimmedstring);
	}
	else
	{
		printf("echec.\n");
	}
	return (0);
}
*/