/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:04:13 by lucilla           #+#    #+#             */
/*   Updated: 2024/04/04 11:32:52 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// implementation of function split, using a specific char to cut the string
// which can either be a char or space or a tab
static int	count_words(const char	*str, char c)
{
	int		cw;
	int		in_word;

	cw = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			cw++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (cw);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		flag;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	flag = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || i == ft_strlen(s)) && flag >= 0)
		{
			split[j++] = word_dup(s, flag, i);
			flag = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int	i = 0;
// 	char	*str = "La vie est belle";
// 	char	c = ' ';
// 	char	**res = ft_split(str, c);
// 	if (res)
// 	{
// 		while (res[i])
// 			printf("Le Mot %d : %s\n", i, res[i]);
// 			free(res[i]);
// 			i++;
// 	}
// 	return 0;
// }

// int main() {
//     const char *input_string = "Ceci est un exemple de texte à découper.";
//     char delimiter = 'e'; // Caractère de délimitation

//     char **result = ft_split(input_string, delimiter);

//     if (result) {
//         int i = 0;
//         while (result[i]) {
//             printf("Mot %d : %s\n", i, result[i]);
//             free(result[i]); 
//             i++;
//         }
//         free(result); 
//     } else {
//         printf("Échec de l'allocation mémoire.\n");
//     }

//     return 0;
// }
