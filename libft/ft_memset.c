/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:38:46 by lufreder          #+#    #+#             */
/*   Updated: 2023/11/01 09:06:18 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tempstr;
	size_t			i;

	i = 0;
	tempstr = (unsigned char *)b;
	while (i < len)
	{
		tempstr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*int main() {
	char buffer[10];

	// Utilisation de ft_memset pour initialiser le tableau buffer avec des 'C'
	ft_memset(buffer, 'C', sizeof(buffer));

	printf("Le tableau buffer a été initialisé avec des 'C'.\n");

	return 0;
}*/