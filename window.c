/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:24:34 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/14 21:33:54 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assignment_texture(t_info *g)
{
	g->ply = mlx_xpm_file_to_image(g->mlx, "textures/p.xpm", &(g->w), &(g->h));
	g->clt = mlx_xpm_file_to_image(g->mlx, "textures/cl.xpm", &(g->w), &(g->h));
	g->ex = mlx_xpm_file_to_image(g->mlx, "textures/cdr.xpm", &(g->w), &(g->h));
	g->wal = mlx_xpm_file_to_image(g->mlx, "textures/wl.xpm", &(g->w), &(g->h));
	g->sp = mlx_xpm_file_to_image(g->mlx, "textures/rd.xpm", &(g->w), &(g->h));

}

void	draw_image(t_info *g, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (g->divide[++i])
		printf("%s\n",g->divide[i]);
		
	
	// while (g->divide[++i])
	// {
	// 	j = -1;
	// 	x = 0;
	// 	while (g->divide[i][++j])
	// 	{
	// 		if (g->divide[i][j] == 'P')	
	// 			mlx_put_image_to_window(g->mlx, g->win, g->ply, x * 50, y);
	// 		if (g->divide[i][j] == 'C')
	// 			mlx_put_image_to_window(g->mlx, g->win, g->clt, x * 50, y);
	// 		if (g->divide[i][j] == 'E')
	// 			mlx_put_image_to_window(g->mlx, g->win, g->ex, x * 50, y);
	// 		if (g->divide[i][j] == '1')
	// 			mlx_put_image_to_window(g->mlx, g->win, g->wal, x * 50, y);
	// 		if (g->divide[i][j] == '0')
	// 			mlx_put_image_to_window(g->mlx, g->win, g->sp, x * 50, y);
	// 		x++;
	// 	}
	// 	y += 50;
	// }
}

void	get_win_size(t_info *game)
{
	game->wid = ft_strlen(game->divide[0]);
	game->het = 0;
	while (game->divide[game->het])
		game->het++;
}

void	ft_graphic(t_info *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_win_size(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->wid * 50, game->het * 50, "test");
	assignment_texture(game);
	draw_image(game, x, y);
	mlx_loop(game->mlx);
	// free(mlx_ptr);
	//1) i must initialyse the components
}
