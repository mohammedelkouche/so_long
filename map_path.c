/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:38:08 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/18 13:29:38 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_info *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->px = j;
				game->py = i;
			}
		}
	}
}

void	fillmap(t_info *game, int py, int px)
{
	if (game->map_cpy[py][px] == '1' || game->map_cpy[py][px] == 'E' ||
	game->map_cpy[py][px] == 'A')
		return ;
	game->map_cpy[py][px] = 'A';
	fillmap(game, py + 1, px);
	fillmap(game, py - 1, px);
	fillmap(game, py, px + 1);
	fillmap(game, py, px - 1);
}

// verifier s'il exist 'C' nom replacer par 'A' and  check 'E' s'il est
// un de c'est cote se retrouve 'A'
int	check_path(t_info *game)
{
	int		i;
	int		j;

	i = -1;
	player_position(game);
	fillmap(game, game->py, game->px);
	while (game->map_cpy[++i])
	{
		j = -1;
		while (game->map_cpy[i][++j])
		{
			if (game->map_cpy[i][j] == 'C')
				return (0);
			if (game->map_cpy[i][j] == 'E' && game->map_cpy[i + 1][j] != 'A' &&
			game->map_cpy[i - 1][j] != 'A' && game->map_cpy[i][j + 1] != 'A' &&
			game->map_cpy[i][j - 1] != 'A')
				return (0);
		}
	}
	return (1);
}
