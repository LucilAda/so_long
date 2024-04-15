/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:30:58 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/13 10:05:37 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp_dst;
	char	*temp_src;

	temp_dst = (char *)dst;
	temp_src = (char *)src;
	if (temp_dst > temp_src)
	{
		while (n--)
			temp_dst[n] = temp_src[n];
	}
	else
		ft_memcpy(temp_dst, temp_src, n);
	return (dst);
}

/*#include<stdio.h>

int	main(void)
{
	char	dst[] = "lorem ip";
	char	src[] = "Trompettiste";

	ft_memmove(dst, src, 8);
	printf("%s\n", dst);
	return (0);
}*/