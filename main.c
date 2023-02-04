/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/04 21:10:08 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// void free_all(char **map)
// {
// 	int index;

//  index = 0
// 	while(map[index])
// 	{
// 		free(map[index]);
// 		index++;
// 	}
// 	free(map);
// }

// read map , push it in array 2 dimention
void	readmap(int fd, char *linemap)
{
	static char	*sjoin;
	char		**divide;
	int			count;
	int			len;

	count = 0;
	len = ft_strlen(linemap);
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
	// free_all(divide);
	if (checkwall(divide, count, len) == 1)
		printf("hello");
	else
		printf("not valide");
}

int	main(void)
{
	int		fd;
	char	*linemap;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		exit(1);
	linemap = get_next_line(fd);
	readmap(fd, linemap);
	// system("leaks a.out");
}

// void	ft_count_line (fd)
// {
// 	while (1) {
// 		if (gnl(fd) == NULL)
// 			break ;
// 		count++;
// 	}
// 	rtn (cnt);
// }

// map[i] = gnl(fd);

// map[0] != '1'

// map[len] != '1';

// map[i][0] != '1';
// map[i][len] != '1';
