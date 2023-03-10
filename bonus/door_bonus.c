/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:25:33 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/28 12:31:35 by mel-kouc         ###   ########.fr       */
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
	j->ex = mlx_xpm_file_to_image(j->mx, "bonus/textures/odr.xpm",
			&(j->w), &(j->h));
	if (!j->ex)
	{
		ft_printf("Error in images\n");
		free_all(j->map, j->map_cpy);
	}
	mlx_put_image_to_window(j->mx, j->win, j->ex, j->dx * 50, j->dy * 50);
}
