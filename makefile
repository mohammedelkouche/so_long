# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 22:54:17 by mel-kouc          #+#    #+#              #
#    Updated: 2023/02/23 10:59:15 by mel-kouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNAME = so_long_bonus

SRC = man/main.c man/parsing.c man/map_path.c man/window.c man/move.c man/closewin.c
BONUS = bonus/main_bonus.c bonus/parsing_bonus.c bonus/map_path_bonus.c bonus/window_bonus.c bonus/move_bonus.c bonus/closewin_bonus.c bonus/door_bonus.c bonus/failure_bonus.c bonus/enemy_bonus.c


OSRC = $(SRC:%.c=%.o)
OBONUS = $(BONUS:.c=.o)

CC = cc
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

all :$(NAME)

bonus: $(OBONUS)
	make -C libft/
	make -C ft_printf/
	$(CC) $(CFLAGS) $(MLX) $(OBONUS)  $(PRINTF) $(LIBFT)  -o $(BNAME)

$(NAME) : $(OSRC)
	make -C libft/
	make -C ft_printf/
	$(CC) $(CFLAGS) $(MLX) $(OSRC)  $(PRINTF) $(LIBFT)  -o $(NAME)

%.o: %.c man/so_long.h bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OSRC) $(OBONUS)

fclean : clean
	rm -rf libft/*.o ft_printf/*.o $(NAME) $(BNAME) $(LIBFT) $(PRINTF)

re : fclean all

.phoney : re fclean clean all