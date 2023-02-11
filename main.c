/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/11 22:23:52 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// void	free_all(char **map)
// {
// 	int	index;

// 	index = 0;
// 	while (map[index])
// 	{
// 		free(map[index]);
// 		index++;
// 	}
// 	free(map);
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_arg(char *arg)
{
	int		lengh;
	char	*mapextension;

	lengh = ft_strlen(arg);
	if (ft_strncmp(".ber", &arg[lengh - 4], 4))
		return (1);
	return (0);
}

// read map , push it in array 2 dimention
void	readmap(int fd, char *linemap, int len)
{
	static char	*sjoin;
	char		**divide;
	int			count;

	count = 0;
	if (!sjoin)
		sjoin = ft_strdup("");
	while (linemap)
	{
		sjoin = ft_strxjoin(sjoin, linemap);
		count++;
		free(linemap);
		linemap = get_next_line(fd);
	}
	divide = ft_split(sjoin, '\n');
	if (parsing(divide, count, len, sjoin))
		printf("valid");
	else
		printf("not valide");
	if (!check_path(divide))
		printf("pathe not valid");
	// free_all(divide);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*linemap;
	int		len;

	if (argc == 2)
	{
		if (check_arg(argv[1]))
			printf ("map description file must end with the .ber extension ");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("error in name of map");
			exit(1);
		}
		linemap = get_next_line(fd);
		len = ft_strlen(linemap);
		readmap(fd, linemap, len);
		// system("leaks a.out");
	}
	else
		printf("numbre of arguments is not correct");
	return (0);
}

