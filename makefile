# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 22:54:17 by mel-kouc          #+#    #+#              #
#    Updated: 2023/02/18 22:59:51 by mel-kouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNAME = so_long_bonus

FSRC = 
BFSRC = 

OSRC = $(FSRC:.c=.o);
BOSRC = $(BFSRC:.c=.o);

all :$(NAME)

$(NAME) : 
	cc -Wall -Wextra -Werror $(FSRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	cc -Wall -Wextra -Werror $(OSRC) $>

clean :
	rm -rf $(OSRC)
	rm -rf ./*.o

fclean : clean
	rm -rf $(NAME) $(BNAME)

re : all fclean

.phoney : re fclean clean all