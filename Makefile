# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 13:44:48 by iprokofy          #+#    #+#              #
#    Updated: 2018/01/14 13:47:21 by iprokofy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Game.cpp\
		Item.cpp\
		ItemList.cpp\
		Player.cpp\
		Enemy.cpp\
		Bullet.cpp\
		main.cpp
NAME = ft_retro
FLAGS = -Wall -Wextra -Werror -lcurses

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(SRC:.cpp=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all