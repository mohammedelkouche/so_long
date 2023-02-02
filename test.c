/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/02 22:22:48 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// void	checkwall(char **line, int count, int len)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (i <= count)
// 	{
// 		j = 0;
// 		while (j < len)
// 		{
// 			if (i == 0 || i == count)
// 		}
// 	}

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
	printf("%d", len);
	if (!sjoin)
		sjoin = ft_strdup("");
	while (linemap)
	{
		sjoin = ft_strxjoin(sjoin, linemap);
		count++;
		linemap = get_next_line(fd);
	}
	// printf("%d", count);
	divide = ft_split(sjoin, '\n');
	checkwall(divide, count, len);
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
