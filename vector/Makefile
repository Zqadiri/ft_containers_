# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 21:54:26 by zqadiri           #+#    #+#              #
#    Updated: 2022/04/24 21:57:21 by zqadiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	vector

SRCS		=  	main.cpp

OBJS		= 	$(SRCS:.cpp=.o)

CC			= 	c++

FLAGS		=	-std=c++98 -g

WWW			=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(SRCS)
			@ $(CC) $(FLAGS) $(WWW) $(SRCS) -o $(NAME)

clean:		
			@ rm -f $(OBJS)

fclean:		clean
			@ rm -f $(NAME)

re:			fclean $(NAME)

.PHONY: 	all fclean clean re
