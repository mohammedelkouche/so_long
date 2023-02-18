/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:55:54 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/18 16:49:57 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_info *j)
{
	if (j->map[j->py][j->px + 1] == 'E' && j->ctclt == 0)
		ft_close_window(j);
	if (j->map[j->py][j->px + 1] != '1' && j->map[j->py][j->px + 1] != 'E')
	{
		if (j->map[j->py][j->px + 1] == 'C')
			j->ctclt--;
		j->map[j->py][j->px + 1] = '0';
		mlx_put_image_to_window(j->mx, j->win, j->sp, j->px * 50, j->py * 50);
		j->px += 1;
		mlx_put_image_to_window(j->mx, j->win, j->ply, j->px * 50, j->py * 50);
		nbr_move();
	}
}

void	ft_move_left(t_info *j)
{
	if (j->map[j->py][j->px - 1] == 'E' && j->ctclt == 0)
		ft_close_window(j);
	if (j->map[j->py][j->px - 1] != '1' && j->map[j->py][j->px - 1] != 'E')
	{
		if (j->map[j->py][j->px - 1] == 'C')
			j->ctclt--;
		j->map[j->py][j->px - 1] = '0';
		mlx_put_image_to_window(j->mx, j->win, j->sp, j->px * 50, j->py * 50);
		j->px -= 1;
		mlx_put_image_to_window(j->mx, j->win, j->ply, j->px * 50, j->py * 50);
		nbr_move();
	}
}

void	ft_move_up(t_info *j)
{
	if (j->map[j->py - 1][j->px] == 'E' && j->ctclt == 0)
		ft_close_window(j);
	if (j->map[j->py - 1][j->px] != '1' && j->map[j->py - 1][j->px] != 'E')
	{
		if (j->map[j->py - 1][j->px] == 'C')
			j->ctclt--;
		j->map[j->py - 1][j->px] = '0';
		mlx_put_image_to_window(j->mx, j->win, j->sp, j->px * 50, j->py * 50);
		j->py -= 1;
		mlx_put_image_to_window(j->mx, j->win, j->ply, j->px * 50, j->py * 50);
		nbr_move();
	}
}

void	ft_move_down(t_info *j)
{
	if (j->map[j->py + 1][j->px] == 'E' && j->ctclt == 0)
		ft_close_window(j);
	if (j->map[j->py + 1][j->px] != '1' && j->map[j->py + 1][j->px] != 'E')
	{
		if (j->map[j->py + 1][j->px] == 'C')
			j->ctclt--;
		j->map[j->py + 1][j->px] = '0';
		mlx_put_image_to_window(j->mx, j->win, j->sp, j->px * 50, j->py * 50);
		j->py += 1;
		mlx_put_image_to_window(j->mx, j->win, j->ply, j->px * 50, j->py * 50);
		nbr_move();
	}
}

int	ft_click(int keycode, t_info *j)
{
	if (keycode == 124)
		ft_move_right(j);
	else if (keycode == 123)
		ft_move_left(j);
	else if (keycode == 126)
		ft_move_up(j);
	else if (keycode == 125)
		ft_move_down(j);
	else if (keycode == 53)
		ft_close_window(j);
	return (0);
}
