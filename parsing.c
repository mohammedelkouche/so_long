/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:25:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/04 21:09:09 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	checkwall(char **line, int count, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < len - 1)
		{
			if (i == 0 || i == (count - 1))
			{
				if (line[i][j] != '1')
					return (0);
			}
			if (j == 0 || j == len - 2)
			{
				if (line[i][j] != '1' || line[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
		return (1);
	}
}
