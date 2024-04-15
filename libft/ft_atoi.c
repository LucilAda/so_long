/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:43:59 by lufreder          #+#    #+#             */
/*   Updated: 2023/10/31 13:27:03 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				result;
	int				sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*#include<stdio.h>

int	main(void)
{
	char	str[] = "   -----++++1234abc";
	
	printf("Le résultat est %d\n", ft_atoi(str));

	char	str1[] = "    -1234abc";

	printf("Le résultat est %d\n", ft_atoi(str1));

	char	str2[] = "    -abc1234abc";

	printf("Le résultat est %d\n", ft_atoi(str2));

}*/