/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/01/31 21:39:58 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// read map
int	main(void)
{
	char	*linemap;
	char	*sjoin;
	int		fd;

	fd = open("map.ber", O_RDONLY);
	linemap = get_next_line(fd);
	if (!sjoin)
		ft_strdup("");
	while (linemap)
	{
		printf("%s", linemap);
		sjoin = ft_strjoin(sjoin, linemap);
		linemap = get_next_line(fd);
	}
	printf("%s", sjoin);
}
