/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:55:54 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/22 21:49:18 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_right(t_info *j)
{
	j->ply = mlx_xpm_file_to_image(j->mx, "textures/p_R.xpm", &(j->w), &(j->h));
	if (j->map[j->py][j->px + 1] != '1')
		print_move(j);
	if (j->ctclt == 0)
		opendoor(j);
	if (j->map[j->py][j->px + 1] == 'E' && j->ctclt == 0)
		ft_win_window(j);
	if (j->map[j->py][j->px + 1] == 'M')
		ft_close_window(j);
	if (j->map[j->py][j->px + 1] != '1' && j->map[j->py][j->px + 1] != 'E')
	{
		if (j->map[j->py][j->px + 1] == 'C')
			j->ctclt--;
		j->map[j->py][j->px] = '0';
		mlx_put_image_to_window(j->mx, j->win, j->sp, j->px * 50, j->py * 50);
		j->px += 1;
		j->map[j->py][j->px] = 'P';
		mlx_put_image_to_window(j->mx, j->win, j->ply, j->px * 50, j->py * 50);
	}
}

void	ft_move_left(t_info *j)
{
	j->ply = mlx_xpm_file_to_image(j->mx, "textures/p_L.xpm", &(j->w), &(j->h));
	if (j->map[j->py][j->px - 1] != '1')
		print_move(j);
	if (j->ctclt == 0)
		opendoor(j);
	if (j->map[j->py][j->px - 1] == 'E' && j->ctclt == 0)
		ft_win_window(j);
	if (j->map[j->py][j->px - 1] == 'M')
		ft_close_window(j);
	if (j->map[j->py][j->px - 1] != '1' && j->map[j->py][j->px - 1] != 'E')
	{
		if (j->map[j->py][j->px - 1] == 'C')
			j->ctclt--;
		j->map[j->py][j->px] = '0';
		mlx_put_image_to_window(j->mx, j->win, j->sp, j->px * 50, j->py * 50);
		j->px -= 1;
		j->map[j->py][j->px] = 'P';
		mlx_put_image_to_window(j->mx, j->win, j->ply, j->px * 50, j->py * 50);
	}
}

void	ft_move_up(t_info *j)
{
	j->ply = mlx_xpm_file_to_image(j->mx, "textures/p.xpm", &(j->w), &(j->h));
	if (j->map[j->py - 1][j->px] != '1')
		print_move(j);
	if (j->ctclt == 0)
		opendoor(j);
	if (j->map[j->py - 1][j->px] == 'E' && j->ctclt == 0)
		ft_win_window(j);
	if (j->map[j->py - 1][j->px] == 'M')
		ft_close_window(j);
	if (j->map[j->py - 1][j->px] != '1' && j->map[j->py - 1][j->px] != 'E')
	{
		if (j->map[j->py - 1][j->px] == 'C')
			j->ctclt--;
		j->map[j->py][j->px] = '0';
		mlx_put_image_to_window(j->mx, j->win, j->sp, j->px * 50, j->py * 50);
		j->py -= 1;
		j->map[j->py][j->px] = 'P';
		mlx_put_image_to_window(j->mx, j->win, j->ply, j->px * 50, j->py * 50);
	}
}

void	ft_move_down(t_info *j)
{
	j->ply = mlx_xpm_file_to_image(j->mx, "textures/p.xpm", &(j->w), &(j->h));
	if (j->map[j->py + 1][j->px] != '1')
		print_move(j);
	if (j->ctclt == 0)
		opendoor(j);
	if (j->map[j->py + 1][j->px] == 'E' && j->ctclt == 0)
		ft_win_window(j);
	if (j->map[j->py + 1][j->px] == 'M')
		ft_close_window(j);
	if (j->map[j->py + 1][j->px] != '1' && j->map[j->py + 1][j->px] != 'E')
	{
		if (j->map[j->py + 1][j->px] == 'C')
			j->ctclt--;
		j->map[j->py][j->px] = '0';
		mlx_put_image_to_window(j->mx, j->win, j->sp, j->px * 50, j->py * 50);
		j->py += 1;
		j->map[j->py][j->px] = 'P';
		mlx_put_image_to_window(j->mx, j->win, j->ply, j->px * 50, j->py * 50);
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
