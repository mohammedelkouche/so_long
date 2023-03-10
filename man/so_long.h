/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:38:33 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/28 12:24:46 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <mlx.h>
# include <stdlib.h>

typedef struct s_info {
	char	**map;
	char	**map_cpy;
	int		px;
	int		py;
	int		ctclt;
	int		w;
	int		h;
	void	*mx;
	void	*win;
	void	*ply;
	void	*clt;
	void	*ex;
	void	*wal;
	void	*sp;
	int		wid;
	int		het;
}	t_info;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	parsing(t_info *game, int count, int len, char *sjoin);
int		check_path(t_info *game);
void	ft_graphic(t_info *game);
int		ft_click(int keycode, t_info *j);
void	nbr_move(void);
void	ft_close_window(t_info *j);
int		ft_cross(t_info *j);
void	free_all(char **map, char **map_cpy);
void	protection(void *failur, t_info *game);
void	check_newline(char *linemap);

#endif