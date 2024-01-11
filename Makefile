# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 17:20:22 by gdel-cas          #+#    #+#              #
#    Updated: 2024/01/11 18:17:37 by gdel-cas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRCs = 







OBJs = $(SRCs:.c=.o)

all: $(NAME)

$(NAME):	$(OBJs)
	ar rcs $(NAME) $(OBJs)

%.o:	%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJs)

fclean: clean
	$(RM) $(NAME)

re:	fclean all




.PHONY: all clean fclean re
.SILENT: all $(NAME) $(OBJs) clean fclean re
