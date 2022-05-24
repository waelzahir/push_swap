# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 18:12:29 by ozahir            #+#    #+#              #
#    Updated: 2022/05/20 18:12:30 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIB = LIB/libft.a
PRINT = PRINT/libftprintf.a
GNL = GNL/gnl.a
HEADER = inc/push_swap.h
SRC_DIR = src
OBJ_DIR = obj
CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap
MAIN = main.c

sources = arr_qs.c get_vals.c init_stack.c moves_1.c moves_3.c pla.c \
	check_vals.c indexing_func.c managing_funcs.c moves_2.c moves_helpers.c \
	push_swap.c
SRC = $(addprefix $(SRC_DIR)/, $(sources))

OBJ = $(addprefix $(OBJ_DIR)/, $(sources:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	${CC} ${FLAGS}  -c $< -o $@

$(NAME): $(PRINT) $(LIB) $(MAIN) $(OBJ)
	$(CC) $(FLAGS) $(MAIN) $(OBJ) $(PRINT) $(LIB) -o $(NAME)

all: $(NAME)

$(GNL):
	@make -C GNL/

$(LIB):
	@make -C LIB/

$(PRINT):
	@make -C PRINT/

clean:
	@make clean -C LIB/
	@make clean -C PRINT/
	@make clean -C GNL/

fclean: clean
	@rm -rf $(LIB) $(PRINT) $(GNL)
re: fclean all
