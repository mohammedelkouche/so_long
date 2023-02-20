/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closewin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:56:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/20 15:21:55 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_info *j)
{
	static int	nb_mv;
	char		*str;

	nb_mv += 1;
	str = ft_itoa(nb_mv);
	mlx_put_image_to_window(j->mx, j->win, j->wal, 0, 0);
	mlx_put_image_to_window(j->mx, j->win, j->wal, 50, 0);
	mlx_put_image_to_window(j->mx, j->win, j->wal, 100, 0);
	mlx_string_put(j->mx, j->win, 0, 0, 0xFFFFFF, "moves:");
	mlx_string_put(j->mx, j->win, 65, 0, 0xFFFFFF, str);
	free(str);
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