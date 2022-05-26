# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 14:48:46 by ahernand          #+#    #+#              #
#    Updated: 2022/05/26 19:59:48 by ahernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

CXX = clang++ 

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS =	srcs/main.cpp

OBJS = srcs/main.o
		
all : $(NAME)

$(OBJS) : $(SRCS)

$(NAME) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@




# - - - - - - - - - - - - - - - - - #
# - - - - - - T E S T - - - - - - - #
# - - - - - - - - - - - - - - - - - #

test: test_ft test_std
	@./test_ft > ft ; ./test_std > std ; diff ft std ; echo " "

test_ft : $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@

test_std:
	@mv ./srcs/type.hpp				./type.hpp
	@mv ./srcs/iterators/type.hpp	./srcs/type.hpp
	@clang++ -std=c++98 -Wall -Wextra -Werror srcs/main.cpp -o $@
	@mv ./srcs/type.hpp				./srcs/iterators/type.hpp
	@mv ./type.hpp					./srcs/type.hpp

test_vector:
	cd srcs/containers_test && bash do.sh vector

test_map:
	cd srcs/containers_test && bash do.sh map

test_stack:
	cd srcs/containers_test && bash do.sh stack




# - - - - - - - - - - - - - - - - - #
# - - - - C L E A N I N G - - - - - #
# - - - - - - - - - - - - - - - - - #


clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@rm -f test_ft
	@rm -f test_std
	@rm -f std
	@rm -f ft


re:	fclean all
