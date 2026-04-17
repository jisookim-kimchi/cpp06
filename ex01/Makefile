# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/17 12:47:42 by jisokim2          #+#    #+#              #
#    Updated: 2026/04/17 13:45:21 by jisokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = serialize

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17 -g

SRC = Serializer.cpp\
      main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Serializer.hpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re