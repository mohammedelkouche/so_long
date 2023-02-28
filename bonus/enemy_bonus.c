/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:15:34 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/28 12:34:41 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_win_window(t_info *g)
{
	ft_printf("congratulation you win");
	mlx_destroy_window(g->mx, g->win);
	free_all(g->map, g->map_cpy);
}

void	replace(t_info *g)
{
	if (!g->enm)
	{
		ft_printf("Error in images\n");
		free_all(g->map, g->map_cpy);
	}
	if (g->map[g->eny][g->enx] == 'P')
		ft_close_window(g);
	g->map[g->eny][g->enx] = 'M';
	mlx_put_image_to_window(g->mx, g->win, g->enm, g->enx * 50,
		g->eny * 50);
}

void	enemy_move(t_info *g)
{
	g->map[g->eny][g->enx] = '0';
	if (g->dir == 'r')
	{
		mlx_put_image_to_window(g->mx, g->win, g->sp, g->enx * 50, g->eny * 50);
		g->enx += 1;
		g->enm = mlx_xpm_file_to_image(g->mx, "bonus/textures/Rbr.xpm",
				&(g->w), &(g->h));
		replace(g);
	}
	if (g->dir == 'l')
	{
		mlx_put_image_to_window(g->mx, g->win, g->sp, g->enx * 50, g->eny * 50);
		g->enx -= 1;
		g->enm = mlx_xpm_file_to_image(g->mx, "bonus/textures/Rbl.xpm",
				&(g->w), &(g->h));
		replace(g);
	}
}

int	enemy_dir(t_info *g)
{
	static int	j;

	if (j == 2000)
	{
		if (g->map[g->eny][g->enx + 1] == '1'
			|| g->map[g->eny][g->enx + 1] == 'C'
			|| g->map[g->eny][g->enx + 1] == 'E'
			|| g->map[g->eny][g->enx + 1] == 'M')
			g->dir = 'l';
		else if (g->map[g->eny][g->enx - 1] == '1'
			|| g->map[g->eny][g->enx - 1] == 'C'
			|| g->map[g->eny][g->enx - 1] == 'E'
			|| g->map[g->eny][g->enx - 1] == 'M')
			g->dir = 'r';
		enemy_move(g);
		j = 0;
	}
	else
		j++;
	return (0);
}

void	enemy(t_info *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'M')
			{
				game->enx = j;
				game->eny = i;
			}
		}
	}
}

// void	ft_win_window(t_info *g)
// {
// 	ft_printf("congratulation you win");
// 	mlx_destroy_window(g->mx, g->win);
// 	free_all(g->map, g->map_cpy);
// }

// void	enemy_move(t_info *g)
// {
// 	if (g->map[g->eny][g->enx + 1] == '1'
// 		|| g->map[g->eny][g->enx + 1] == 'C'
// 		|| g->map[g->eny][g->enx + 1] == 'E')
// 		// || g->map[g->eny][g->enx + 1] == 'M')
// 		g->dir = 'l';
// 	else if (g->map[g->eny][g->enx - 1] == '1'
// 		|| g->map[g->eny][g->enx - 1] == 'C'
// 		|| g->map[g->eny][g->enx - 1] == 'E')
// 		// || g->map[g->eny][g->enx - 1] == 'M')
// 		g->dir = 'r';
// 	g->map[g->eny][g->enx] = '0';

// 	if (g->dir == 'r')
// 	{
// 		// printf("x = %d\t y = %d\n", g->enx, g->eny);
// 		mlx_put_image_to_window(g->mx, g->win, g->sp, g->enx * 50, g->eny * 50);
// 		g->enx += 1;
// 		g->enm = mlx_xpm_file_to_image(g->mx, "bonus/textures/Rbr.xpm",
// 				&(g->w), &(g->h));
// 		if (g->map[g->eny][g->enx] == 'P')
// 			ft_close_window(g);
// 		g->map[g->eny][g->enx] = 'M';
// 		mlx_put_image_to_window(g->mx, g->win, g->enm, g->enx * 50,
// 			g->eny * 50);
// 	}

// 	if (g->dir == 'l')
// 	{
// 		mlx_put_image_to_window(g->mx, g->win, g->sp, g->enx * 50, g->eny * 50);
// 		g->enx -= 1;
// 		g->enm = mlx_xpm_file_to_image(g->mx, "bonus/textures/Rbl.xpm",
// 				&(g->w), &(g->h));
// 		if (g->map[g->eny][g->enx] == 'P')
// 			ft_close_window(g);
// 		g->map[g->eny][g->enx] = 'M';
// 		mlx_put_image_to_window(g->mx, g->win, g->enm, g->enx * 50,
// 			g->eny * 50);
// 	}
// }

// int	enemy_dir(t_info *g)
// {
// 	static int	j;

// 	if (j == 6000)
// 	{
// 		enemy(g);
// 		j = 0;
// 	}
// 	else
// 		j++;
// 	return (0);
// }

// void	enemy(t_info *game)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (game->map[++i])
// 	{
// 		j = -1;
// 		while (game->map[i][++j])
// 		{
// 			if (game->map[i][j] == 'M')
// 			{
// 				game->enx = j;
// 				game->eny = i;
// 				enemy_move(game);
// 			}
// 		}
// 	}
// }
