# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/17 12:48:21 by jisokim2          #+#    #+#              #
#    Updated: 2026/04/17 13:47:12 by jisokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ex02

CXX = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++17

SRC_DIR = SRC/
OBJ_DIR = OBJ/
HEADER_DIR = HEADER/

SRC = $(SRC_DIR)A.cpp \
		$(SRC_DIR)B.cpp \
		$(SRC_DIR)C.cpp\
		$(SRC_DIR)Base.cpp\
		$(SRC_DIR)main.cpp\

OBJ = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re