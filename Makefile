NAME = miniRT
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = main.c \
	parser_params.c \
	parser_file.c \
	utils.c

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

DIR_LIBFT = libft
LIBFT = $(DIR_LIBFT)/libft.a

DIR_OBJS = objs
OBJS = $(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

INCLUDES = -I$(MLX_DIR) -I$(DIR_LIBFT)

MAKEFLAGS += --silent

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	@make bonus -C $(DIR_LIBFT)
	@echo "libft compiled"

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

$(MLX_DIR):
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	@echo "minilibx-linux cloned"

$(MLX_LIB): $(MLX_DIR)
	@make -C $(MLX_DIR) CC=gcc

$(DIR_OBJS)/%.o: %.c | $(DIR_OBJS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L$(DIR_LIBFT) -lft -o $(NAME)
	@echo "MiniRT compiled"


clean:
	@make -C $(MLX_DIR) clean
	@make -C $(DIR_LIBFT) clean
	@rm -rf $(OBJS)
	@rm -rf $(DIR_OBJS)
	@echo "MiniRT cleaned"

fclean: clean
	@make -C $(DIR_LIBFT) fclean
	@rm -rf $(NAME)
	@echo "MiniRT fcleaned"

re: fclean all

.PHONY: all clean fclean re
