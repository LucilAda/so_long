/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:24:34 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/18 16:25:08 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

//n_bytes = 1: initialize at 1 to suggest there is at least one loop
//n_bytes == -1: if there was an error in reading
//n_bytes == 0: means we reach EOF so we break to out from the loop
//tmp = strdup(""): create an empty string if there is nothing in tmp
//result = tmp: store tmp in result
//then store the joined string formed with result and buffer in tmp

char	*store_reading(char *storage, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(storage, buffer);
	free(storage);
	storage = NULL;
	return (tmp);
}

char	*read_the_line(int fd, char *buffer, char *tmp)
{
	char	*storage;
	int		n_bytes;

	n_bytes = 1;
	while (n_bytes)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			if (tmp)
				free(tmp);
			return (NULL);
		}
		else if (n_bytes == 0)
			break ;
		buffer[n_bytes] = '\0';
		if (!tmp)
			tmp = ft_strdup("");
		storage = tmp;
		tmp = store_reading(storage, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (tmp);
}

//get the text after \n
//we store in storage the substring extracted from line at index after '\n'
//from the size of the line without first char which is '\n'
char	*extract(char *line)
{
	char	*storage;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (NULL);
	storage = _ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!storage)
	{
		return (NULL);
	}
	if (storage[0] == '\0')
	{
		free (storage);
		storage = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (storage);
}

//if (fd < 0 || BUFFER_SIZE <= 0) : if there is a reading error anywhere
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*tmp = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line = read_the_line(fd, buffer, tmp);
	free(buffer);
	if (!line)
	{
		tmp = NULL;
		return (NULL);
	}
	tmp = extract(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;

// 	fd = open("42_with_nl.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	printf("THE FIRST LINE IS: %s\n", get_next_line(fd));
// 	printf("THE SECOND LINE IS: %s\n", get_next_line(fd));
// 	printf("THE THIRD LINE IS: %s\n", get_next_line(fd));
// 	printf("THE FOURTH LINE IS: %s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }