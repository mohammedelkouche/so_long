/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:47:54 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/02 10:26:09 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_getstore(int fd, char *stor);
int		ft_gstrchr(char *s, char c);
char	*ft_strjoin(char *prdata, char *buff);
size_t	ft_strlen(const char *s);
char	*ft_getline(char	*str);
char	*ft_nextstr(char *s);
char	*ft_strdup(const char *s1);
#endif
