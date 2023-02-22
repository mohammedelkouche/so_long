/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:19:32 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/22 10:48:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeall(char *data, char *buffer)
{
	free(data);
	free(buffer);
	return (NULL);
}

char	*ft_strxdup(const char *s1)
{
	size_t	len;
	char	*str;
	int		i;

	i = 0;
	len = ft_strxlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_gstrchr(char *s, char c)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}

char	*ft_getstore(int fd, char *stor)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!stor)
		stor = ft_strxdup("");
	read_bytes = 1;
	while (ft_gstrchr(stor, '\n') == -1 && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1 && stor)
			return (freeall(stor, buffer));
		if (read_bytes <= 0 && !stor[0])
			return (freeall(stor, buffer));
		else if (read_bytes == 0 && stor)
			break ;
		buffer[read_bytes] = '\0';
		stor = ft_strxjoin(stor, buffer);
	}
	free(buffer);
	return (stor);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_getstore(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_getline(storage);
	storage = ft_nextstr(storage);
	return (line);
}
