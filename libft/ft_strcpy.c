/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:54:09 by lucilla           #+#    #+#             */
/*   Updated: 2023/11/06 13:57:33 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(int argc, char *argv[])
{
	int	i;
	if (argc == 3)
	{
		ft_strcpy(argv[1], argv[2]);
		i = 0;
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	return (0);
}*/
