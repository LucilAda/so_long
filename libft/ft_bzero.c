/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:58:43 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/04 11:32:29 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp_ptr;

	temp_ptr = (char *)s;
	while (n > 0)
	{
		*temp_ptr = 0;
		temp_ptr++;
		n--;
	}
}

/*#include<stdio.h>

int	main(void)
{
	char str[] = "Hello";
	ft_bzero(str, 5);

	printf("%s\n", str);

	return (0);
}*/