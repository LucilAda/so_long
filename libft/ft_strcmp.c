/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucilla <lucilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:55:03 by lucilla           #+#    #+#             */
/*   Updated: 2023/11/10 12:08:32 by lucilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*int main(int argc, char *argv[])
{
    int result;
    if (argc == 3)
    {
        result = ft_strcmp(argv[1], argv[2]);
        char result_str[12]; // As the maximum result can be -127 to 127
        int len = sprintf(result_str, "%d\n", result);
        write(1, result_str, len); // 1 is the file descriptor for standard 
        return result;
    }
    return 0;
}*/
