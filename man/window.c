/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:24:34 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/28 12:25:55 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assignment_texture(t_info *g)
{
	g->ply = mlx_xpm_file_to_image(g->mx, "man/textures/p.xpm",
			&(g->w), &(g->h));
	g->clt = mlx_xpm_file_to_image(g->mx, "man/textures/cl.xpm",
			&(g->w), &(g->h));
	g->ex = mlx_xpm_file_to_image(g->mx, "man/textures/cdr.xpm",
			&(g->w), &(g->h));
	g->wal = mlx_xpm_file_to_image(g->mx, "man/textures/wl.xpm",
			&(g->w), &(g->h));
	g->sp = mlx_xpm_file_to_image(g->mx, "man/textures/rd.xpm",
			&(g->w), &(g->h));
	if (!g->ply || !g->clt || !g->ex || !g->wal || !g->sp)
	{
		ft_printf("Error in images\n");
		free_all(g->map, g->map_cpy);
	}
}

void	draw_image(t_info *g, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		x = 0;
		while (g->map[i][++j])
		{
			mlx_put_image_to_window(g->mx, g->win, g->sp, x * 50, y);
			if (g->map[i][j] == 'P')
				mlx_put_image_to_window(g->mx, g->win, g->ply, x * 50, y);
			if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mx, g->win, g->clt, x * 50, y);
			if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mx, g->win, g->ex, x * 50, y);
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->mx, g->win, g->wal, x * 50, y);
			x++;
		}
		y += 50;
	}
}

void	get_win_size(t_info *game)
{
	game->wid = ft_strlen(game->map[0]);
	game->het = 0;
	while (game->map[game->het])
		game->het++;
}

void	ft_graphic(t_info *mp)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_win_size(mp);
	if (mp->wid * 50 > 2450 || mp->het * 50 > 1250)
	{
		ft_printf("width and height of map is greater than screen");
		free_all(mp->map, mp->map_cpy);
	}
	mp->mx = mlx_init();
	protection(mp->mx, mp);
	mp->win = mlx_new_window(mp->mx, mp->wid * 50, mp->het * 50, "so_long");
	protection(mp->win, mp);
	assignment_texture(mp);
	draw_image(mp, x, y);
	mlx_hook(mp->win, 2, 0, ft_click, mp);
	mlx_hook(mp->win, 17, 0, ft_cross, mp);
	mlx_loop(mp->mx);
}
