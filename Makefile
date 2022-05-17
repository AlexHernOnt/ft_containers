# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 14:48:46 by ahernand          #+#    #+#              #
#    Updated: 2022/05/17 20:37:06 by ahernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

CXX = clang++ 

CPPFLAGS = -std=c++98 #-Wall -Wextra -Werror

SRCS =	srcs/main.cpp

OBJS = srcs/main.o
		
all : $(NAME)

$(OBJS) : $(SRCS)

$(NAME) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@




# - - - - - - - - - - - - - - - - - #
# - - - - C L E A N I N G - - - - - #
# - - - - - - - - - - - - - - - - - #

test:
	cd srcs/containers_test && sh do.sh map

test_vector:
	cd srcs/containers_test && sh do.sh vector

clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)

re:	fclean all clean
