/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:42:06 by lufreder          #+#    #+#             */
/*   Updated: 2023/10/30 15:08:23 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = (c - 32);
	return (c);
}

/*#include<stdio.h>

int main(void)
{
    printf("%c", ft_toupper(49));
    return (0);
}*/