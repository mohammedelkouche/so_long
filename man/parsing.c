/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:25:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/21 23:30:43 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_cpn(t_info *game, int count, int len, int i)
{
	int	j;

	while (++i < count && game->map[i])
	{
		j = -1;
		while (++j < len - 1)
		{
			if (i == 0 || i == (count - 1))
			{
				if (game->map[i][j] != '1')
					return (0);
			}
			if (j == 0 || j == len - 2)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
			if (game->map[i][j] != '1' && game->map[i][j] != '0' &&
			game->map[i][j] != 'E' && game->map[i][j] != 'P' &&
			game->map[i][j] != 'C')
				return (0);
		}
	}
	return (1);
}

int	check_nbcpn(t_info *game, char *sjoin)
{
	int	i;
	int	ctplay;
	int	ctexit;

	ctplay = 0;
	ctexit = 0;
	i = 0;
	while (sjoin[i])
	{
		if (sjoin[i] == 'E')
			ctexit++;
		if (sjoin[i] == 'P')
			ctplay++;
		if (sjoin[i] == 'C')
			game->ctclt++;
		i++;
	}
	if (ctexit != 1 || ctplay != 1 || game->ctclt < 1)
		return (0);
	return (1);
}

int	check_regt(t_info *game, int len)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != (len - 1))
			return (0);
		i++;
	}
	return (1);
}

void	parsing(t_info *game, int count, int len, char *sjoin)
{
	int	i;

	i = -1;
	if (!check_wall_cpn(game, count, len, i))
	{
		ft_printf("map not closed by walls or wrong component");
		free_all(game->map, game->map_cpy);
	}
	if (!check_nbcpn(game, sjoin))
	{
		ft_printf("number of components not valid");
		free_all(game->map, game->map_cpy);
	}
	if (!check_regt(game, len))
	{
		ft_printf("The map is not rectangular");
		free_all(game->map, game->map_cpy);
	}
}
