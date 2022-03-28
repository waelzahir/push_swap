M_NAME = push_swap
B_NAME = checker


M_MAIN = main.c
B_NAME = main_bonus.c


SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = libft


M_HEADER = $(HEADER_DIR)/push_swap.h
B_HEADER = $(HEADER_DIR)/push_swap_bonus.h

libft = $(LIB_DIR)/libft.a

FLAGS = -Wall -Wextra -Werror

M_SRC = $(SRC_DIR)/parsing.c
s
s
$(libft): 
	make -c libft/