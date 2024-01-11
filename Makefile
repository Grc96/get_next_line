# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 17:20:22 by gdel-cas          #+#    #+#              #
#    Updated: 2024/01/11 19:12:15 by gdel-cas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCs = 

OBJs = $(SRCs:.c=.o)

all = $()


.PHONY: all clean fclean re
.SILENT: all $(NAME) $(OBJs) clean fclean re
