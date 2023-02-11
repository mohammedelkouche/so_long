/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:38:08 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/11 22:22:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	player_position(t_info *game, char **divide)
{
	int	i;
	int	j;

	i = -1;
	game->p_x = 0;
	game->p_y = 0;
	while (divide[++i])
	{
		j = -1;
		while (divide[i][++j])
		{
			if (divide[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
			}
		}
	}
}

void	floodfill(char **divide, int p_y, int p_x, char newc)
{
	if (divide [p_y][p_x] == '1' || divide [p_y][p_x] == 'E' ||
	divide [p_y][p_x] == newc)
		return ;
	if (divide [p_y][p_x] != 'P')
		divide [p_y][p_x] = newc;
	floodfill(divide, p_y + 1, p_x, newc);
	floodfill(divide, p_y - 1, p_x, newc);
	floodfill(divide, p_y, p_x + 1, newc);
	floodfill(divide, p_y, p_x - 1, newc);
}

// verifier s'il exist 'C' nom replacer par 'A' and  chack 'E' s'il est 
// un de c'est cote se retrouve 'A'
int	check_path(char **divide)
{
	t_info	*game;
	char	newc;
	int		i;
	int		j;

	i = -1;
	player_position(game, divide);
	newc = 'A';
	printf("\n");
	floodfill(divide, game->p_y, game->p_x, newc);
	while (divide[++i])
	{
		j = -1;
		while (divide[i][++j])
		{
			if (divide[i][j] == 'C')
				return (0);
			if (divide[i][j] == 'E' && divide[i + 1][j] != 'A' &&
			divide[i - 1][j] != 'A' && divide[i][j + 1] != 'A' &&
			divide[i][j - 1] != 'A')
				return (0);
		}
	}
	return (1);
}
