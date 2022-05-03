NAME = push_swap
NAME_BONUS = checker
MAIN = main.c
MAIN_bonus = checker.c
#FLAGS = -Wall -Wextra -Werror
CC = gcc

PRINT_DIR = ft_printf
LIB_DIR = libft
SRC_DIR = src
OBJ_DIR = obj

HEADER = inc/push_swap.h
HEADER_bonus = inc/checker.h
LIBFT = ${LIB_DIR}/libft.a
PRINTF = ${PRINT_DIR}/libftprintf.a


FILES = check_values.c get_values.c quick_sort.c \
	stack_create.c error_handle.c push_swap_pt1.c \
	moves_pt1.c moves_pt3.c moves_pt2.c moves_add.c \
	push_swap_pt2.c push_swap_pt3.c get_next_line.c \
	get_next_line_utils.c
	
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))



$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	${CC} ${FLAGS}  -c $< -o $@


all: ${NAME}
bonus: ${NAME_BONUS}


${LIBFT}:
	make -C libft/
$(PRINTF):
	make -C ft_printf/


${NAME}: ${PRINTF} ${LIBFT} $(OBJ) ${MAIN} $(HEADER)
	${CC} ${FLAGS}   ${MAIN} ${OBJ} ${LIBFT} ${PRINTF} -o ${NAME}

${NAME_BONUS}: ${PRINTF} ${LIBFT} ${OBJ} ${MAIN_bonus} ${HEADER}
	${CC} ${FLAGS}   ${MAIN_bonus} ${OBJ} ${LIBFT} ${PRINTF} -o ${NAME_BONUS}

clean:
	@rm -rf ${OBJ}
	make clean -C libft/
	make clean -C ft_printf
fclean:
	@rm -rf ${OBJ} ${NAME}
	make fclean -C libft/
	make fclean -C ft_printf

re: fclean all
.phony: all clean fclean re