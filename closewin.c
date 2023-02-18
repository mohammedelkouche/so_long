/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closewin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:56:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/18 23:31:38 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nbr_move(void)
{
	static int	nb_mv;

	nb_mv += 1;
	ft_printf("%d\t", nb_mv);
}

void	check_newline(char *linemap)
{
	if (*linemap == '\n')
	{
		ft_printf("the is a new line in the map");
		exit(1);
	}
}

void	free_all(char **map, char **map_cpy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	while (map_cpy[j])
	{
		free(map_cpy[j]);
		j++;
	}
	free(map_cpy);
	exit (1);
}

void	ft_close_window(t_info *j)
{
	mlx_destroy_window(j->mx, j->win);
	free_all(j->map, j->map_cpy);
}

int	ft_cross(t_info *j)
{
	mlx_destroy_window(j->mx, j->win);
	free_all(j->map, j->map_cpy);
	return (0);
}
// int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
// int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);