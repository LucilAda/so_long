/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:53:01 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/06 15:45:06 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	{
		while (n > 0)
		{
			temp_dst[i] = temp_src[i];
			i++;
			n--;
		}
	}
	return (dst);
}

/*
#include <stdio.h>

int	main(void)
{
	char	dst[] = "Cacahuète";
	char	src[] = "Brouette";

	ft_memcpy(dst, src, 4);
	printf("%s\n", dst);
	return (0);
}*/