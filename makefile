# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 22:54:17 by mel-kouc          #+#    #+#              #
#    Updated: 2023/02/21 23:39:03 by mel-kouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNAME = so_long_bonus

SRC = man/main.c man/parsing.c man/map_path.c man/window.c man/move.c man/closewin.c man/Get-Next-Line/get_next_line.c man/Get-Next-Line/get_next_line_utils.c

BSRC = bonus/main.c bonus/parsing.c bonus/map_path.c bonus/window.c bonus/move.c bonus/closewin.c bonus/door.c bonus/failure bonus/enemy bonus/Get-Next-Line/get_next_line.c bonus/Get-Next-Line/get_next_line_utils.c

OSRC = $(SRC:.c=.o)
BOSRC = $(BSRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all :$(NAME)

$(NAME) : 
	make ./man/libft/
	make ./man/ft_printf/
	$(CC) $(CFLAGS) $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(OSRC) $>

clean :
	rm -rf $(OSRC) $(BOSRC)
	rm -rf ./*.o

fclean : clean
	rm -rf $(NAME) $(BNAME)

re : all fclean

.phoney : re fclean clean all