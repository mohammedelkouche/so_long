/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:25:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/12 10:56:34 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_cpn(char **line, int count, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < len - 1)
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
			if (line[i][j] != '1' && line[i][j] != '0' && line[i][j] != 'E'
			&& line[i][j] != 'P' && line[i][j] != 'C')
				return (0);
		}
	}
	return (1);
}

int	check_nbcpn(char *sjoin, int count, int len)
{
	int	i;
	int	ctplay;
	int	ctexit;
	int	ctclt;

	ctplay = 0;
	ctexit = 0;
	ctclt = 0;
	i = 0;
	while (sjoin[i])
	{
		if (sjoin[i] == 'E')
			ctexit++;
		if (sjoin[i] == 'P')
			ctplay++;
		if (sjoin[i] == 'C')
			ctclt++;
		i++;
	}
	if (ctexit != 1 || ctplay != 1 || ctclt < 1)
		return (0);
	return (1);
}

int	check_regt(char **line, int count, int len)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (strlen(line[i]) != (len - 1))
			return (0);
		i++;
	}
	if (count == len - 1)
		return (0);
	return (1);
}

int	parsing(char **line, int count, int len, char *sjoin)
{
	if (!check_wall_cpn(line, count, len))
	{
		ft_printf("map not closed by walls or component not found");
		return (0);
	}
	if (!check_nbcpn(sjoin, count, len))
	{
		ft_printf("number of components not valid");
		return (0);
	}
	if (!check_regt(line, count, len))
	{
		ft_printf("The map is not rectangular");
		return (0);
	}
	return (1);
}
