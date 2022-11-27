/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:52:19 by oaciz             #+#    #+#             */
/*   Updated: 2022/11/10 22:02:17 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *string)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ftt_strlen(string) - i));
	if (!s)
		return (NULL);
	i++;
	while (string[i])
		s[j++] = string[i++];
	s[j] = '\0';
	free(string);
	return (s);
}

char	*ft_moveline(char *string)
{
	int		i;
	char	*s;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		s[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*ft_read_and_save(int fd, char *string)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes != 0 && !ft_strchr(string))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free(buffer);
	if (!*string)
	{
		free(string);
		return (NULL);
	}
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_and_save(fd, str);
	if (!str)
		return (NULL);
	line = ft_moveline(str);
	str = ft_save(str);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd = 0;
	char *line;
	int 	i;
	
	i = 0;
	fd = open("deneme.txt", O_RDONLY);
	while (i <  20)
	{
    line = get_next_line(fd);
    printf("%s", line);
	i++;
	}
    
}
*/
