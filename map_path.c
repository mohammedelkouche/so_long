/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:38:08 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/12 13:15:31 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_info *game, char **divide)
{
	int	i;
	int	j;

	i = -1;
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

void	floodfill(char **divide, int p_y, int p_x)
{
	if (divide [p_y][p_x] == '1' || divide [p_y][p_x] == 'E' ||
	divide [p_y][p_x] == 'A')
		return ;
	if (divide [p_y][p_x] != 'P')
		divide [p_y][p_x] = 'A';
	floodfill(divide, p_y + 1, p_x);
	floodfill(divide, p_y - 1, p_x);
	floodfill(divide, p_y, p_x + 1);
	floodfill(divide, p_y, p_x - 1);
}

// verifier s'il exist 'C' nom replacer par 'A' and  chack 'E' s'il est 
// un de c'est cote se retrouve 'A'
int	check_path(char **divide, t_info *game)
{
	int		i;
	int		j;

	i = -1;
	game = malloc(sizeof(t_info));
	player_position(game, divide);
	floodfill(divide, game->p_y, game->p_x);
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
