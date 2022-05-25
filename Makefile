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
NAME_B = checker
MAIN_B = checker_main.c

sources = arr_qs.c bools_handle.c check_vals.c double_rotate.c \
	get_vals.c indexing_func.c init_stack.c managing_funcs.c \
	moves_1.c moves_2.c moves_3.c moves_helpers.c pla.c push_swap.c \
	small_sort.c stacks_rotate.c
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
bonus: $(GNL) $(LIB) $(MAIN_B) $(OBJ) $(PRINT)
	$(CC) $(FLAGS) $(MAIN_B) $(OBJ) $(GNL) $(PRINT) $(LIB) -o $(NAME_B)
clean:
	@make clean -C LIB/
	@make clean -C PRINT/
	@make clean -C GNL/

fclean: clean
	@rm -rf $(LIB) $(PRINT) $(GNL) ${NAME} ${OBJ}
re: fclean all
