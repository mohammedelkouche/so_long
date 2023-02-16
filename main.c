/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/16 13:37:01 by mel-kouc         ###   ########.fr       */
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
	char	*mapextension;

	lengh = ft_strlen(arg);
	if (ft_strncmp(".ber", &arg[lengh - 4], 4))
		return (1);
	return (0);
}

// read map , push it in array 2 dimention
void	readmap(int fd, char *linemap, int len, t_info *game)
{
	static char	*sjoin;
	int			count;

	count = 0;
	if (!sjoin)
		sjoin = ft_strdup("");
	while (linemap)
	{
		sjoin = ft_strxjoin(sjoin, linemap);
		count++;
		free(linemap);
		linemap = get_next_line(fd);
	}
	game->map = ft_split(sjoin, '\n');
	game->map_cpy = ft_split(sjoin, '\n');
	if (!parsing(game, count, len, sjoin))
		exit(1);
	if (!check_path(game))
	{
		ft_printf("pathe not valid");
		exit(1);
	}
	// free_all(map);
}

void	function_needed(int fd, t_info *game)
{
	int		len;
	char	*linemap;


	linemap = get_next_line(fd);
	len = ft_strlen(linemap);
	readmap(fd, linemap, len, game);
	ft_graphic(game);
	// ft_move(game);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		len;
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
		// system("leaks a.out");
	}
	else
		ft_printf("numbre of arguments is not correct");
	return (0);
}

// gcc -lmlx -framework OpenGL -framework AppKit main.c Get-Next-Line/get_next_line.c Get-Next-Line/get_next_line_utils.c   libft/ft_split.c libft/ft_strchr.c parsing.c map_path.c ft_printf/ft_printf.c ft_printf/ft_putstr.c ft_printf/ft_putchar.c ft_printf/ft_format.c ft_printf/ft_putadrs.c ft_printf/ft_putnb_hexa.c ft_printf/ft_putnb_u.c ft_printf/ft_putnbr.c window.c move.c