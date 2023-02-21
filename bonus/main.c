/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/21 23:21:26 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_arg(char *arg)
{
	int		lengh;

	lengh = ft_strlen(arg);
	if (ft_strncmp(".ber", &arg[lengh - 4], 4))
		return (1);
	return (0);
}

// read map , push it in array 2 dimention
void	readmap(int fd, int len, t_info *game)
{
	static char	*sjoin;

	game->count = 0;
	if (!sjoin)
		sjoin = ft_strdup("");
	while (game->linemap)
	{
		check_newline(game->linemap);
		sjoin = ft_strxjoin(sjoin, game->linemap);
		game->count++;
		free(game->linemap);
		game->linemap = get_next_line(fd);
	}
	game->map = ft_split(sjoin, '\n');
	game->map_cpy = ft_split(sjoin, '\n');
	parsing(game, len, sjoin);
	if (!check_path(game))
	{
		ft_printf("pathe not valid");
		free_all(game->map, game->map_cpy);
	}
}

void	function_needed(int fd, t_info *game)
{
	int		len;

	game->linemap = get_next_line(fd);
	if (!game->linemap)
	{
		ft_printf("wrong map");
		exit(1);
	}
	len = ft_strlen(game->linemap);
	readmap(fd, len, game);
	ft_graphic(game);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_info	game;

	if (argc == 2)
	{
		if (check_arg(argv[1]))
			ft_printf("map description file must end with the .ber extension ");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("error in name of map");
			exit(1);
		}
		function_needed(fd, &game);
	}
	else
		ft_printf("numbre of arguments is not correct");
	return (0);
}
