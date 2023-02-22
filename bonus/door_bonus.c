/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:25:33 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/22 21:48:51 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	door_position(t_info *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'E')
			{
				game->dx = j;
				game->dy = i;
			}
		}
	}
}

void	opendoor(t_info *j)
{
	door_position(j);
	mlx_put_image_to_window(j->mx, j->win, j->sp, j->dx * 50, j->dy * 50);
	j->ex = mlx_xpm_file_to_image(j->mx, "textures/odr.xpm", &(j->w), &(j->h));
	mlx_put_image_to_window(j->mx, j->win, j->ex, j->dx * 50, j->dy * 50);
}
