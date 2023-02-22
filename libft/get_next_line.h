/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:19:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/02/22 10:49:40 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_getstore(int fd, char *stor);
int		ft_gstrchr(char *s, char c);
char	*ft_strxjoin(char *prdata, char *buff);
size_t	ft_strxlen(const char *s);
char	*ft_getline(char	*str);
char	*ft_nextstr(char *s);
char	*ft_strxdup(const char *s1);
#endif
