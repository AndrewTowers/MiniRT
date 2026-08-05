NAME = miniRT
FLAGS = -Wall -Werror -Wextra -Imlx -lm
SRC = main.c \
	parser.c \
	utils.c

OBJ_SRC = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_SRC)
	make -C minilibx-linux
	make -C libft
	cc $(FLAGS) $(OBJ_SRC) libft/libft.a -o $(NAME)
%.o: %.c
	cc $(FLAGS) -c $< -o $@
clean:
	make -C minilibx-linux clean
	make -C libft clean
	rm -rf $(OBJ_SRC)
fclean: clean
# 	make -C minilibx-linux fclean
	make -C libft fclean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
