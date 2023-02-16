/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:56:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/16 21:06:34 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nbr_move(void)
{
	static int	nb_mv;

	nb_mv += 1;
	ft_printf("%d\t", nb_mv);
}

void	ft_close_window(t_info *j)
{
	mlx_destroy_window(j->mx, j->win);
	exit (1);
}

// int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
// int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);