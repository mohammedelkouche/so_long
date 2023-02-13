/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:38:08 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/13 12:41:17 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_info *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->divide[++i])
	{
		j = -1;
		while (game->divide[i][++j])
		{
			if (game->divide[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
			}
		}
	}
}

void	floodfill(t_info *game, int p_y, int p_x)
{
	if (game->divide [p_y][p_x] == '1' || game->divide [p_y][p_x] == 'E' ||
	game->divide [p_y][p_x] == 'A')
		return ;
	if (game->divide [p_y][p_x] != 'P')
		game->divide [p_y][p_x] = 'A';
	floodfill(game, p_y + 1, p_x);
	floodfill(game, p_y - 1, p_x);
	floodfill(game, p_y, p_x + 1);
	floodfill(game, p_y, p_x - 1);
}

// verifier s'il exist 'C' nom replacer par 'A' and  check 'E' s'il est
// un de c'est cote se retrouve 'A'
int	check_path(t_info *game)
{
	int		i;
	int		j;

	i = -1;
	player_position(game);
	floodfill(game, game->p_y, game->p_x);
	while (game->divide[++i])
	{
		j = -1;
		while (game->divide[i][++j])
		{
			if (game->divide[i][j] == 'C')
				return (0);
			if (game->divide[i][j] == 'E' && game->divide[i + 1][j] != 'A' &&
			game->divide[i - 1][j] != 'A' && game->divide[i][j + 1] != 'A' &&
			game->divide[i][j - 1] != 'A')
				return (0);
		}
	}
	return (1);
}
