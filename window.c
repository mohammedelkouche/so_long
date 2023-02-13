/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:24:34 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/13 21:43:43 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"

void	ft_graphic(t_info *game)
{
	
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1029, 1090, "test");
	mlx_loop(game->mlx_ptr);
	// free(mlx_ptr);
	//1) i must initialyse the components
	//1)
}
