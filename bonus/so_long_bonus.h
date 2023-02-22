/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:38:33 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/22 23:31:45 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info {
	char		**map;
	char		**map_cpy;
	char		*linemap;
	int			count;
	int			px;
	int			py;
	int			dx;
	int			dy;
	int			ctclt;
	int			w;
	int			h;
	void		*mx;
	void		*win;
	void		*ply;
	void		*enm;
	int			enx;
	int			eny;
	void		*clt;
	void		*ex;
	void		*wal;
	void		*sp;
	int			wid;
	int			het;
	char		dir;
}	t_info;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	parsing(t_info *game, int len, char *sjoin);
int		check_path(t_info *game);
void	ft_graphic(t_info *game);
int		ft_click(int keycode, t_info *j);
void	print_move(t_info *j);
void	ft_close_window(t_info *j);
int		ft_cross(t_info *j);
void	free_all(char **map, char **map_cpy);
void	check_newline(char *linemap);
void	opendoor(t_info *j);
char	*ft_itoa(int n);
void	protection(void *failur, t_info *game);
void	enemy(t_info *game);
int		enemy_dir(t_info *g);
void	ft_win_window(t_info *g);
// void	ft_move_right(t_info *j);
// void	ft_move_down(t_info *j);
// void	ft_move_up(t_info *j);
// void	ft_move_left(t_info *j);

#endif