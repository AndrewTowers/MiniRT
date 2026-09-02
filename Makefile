NAME = miniRT
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = main.c \
	parser/parse_camera.c \
	parser/parse_component.c \
	parser/parse_elements.c \
	parser/parse_light.c \
	parser/parse_file.c \
	parser/parse_params.c \
	utils/objects.c \
	utils/utils.c \
	utils/utils_3.c \
	draw/draw_utils.c \
	draw/draw.c \
	close/closed.c

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
	make bonus -C $(DIR_LIBFT)
	echo "libft compiled"

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(MLX_DIR):
	git clone -q https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	echo "Minilibx-linux cloned"

$(MLX_LIB): $(MLX_DIR)
	cd $(MLX_DIR) && ./configure

$(DIR_OBJS)/%.o: %.c | $(DIR_OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L$(DIR_LIBFT) -lft -o $(NAME)
	echo "MiniRT compiled"

clean:
	make -C $(DIR_LIBFT) clean
	rm -rf $(OBJS)
	rm -rf $(DIR_OBJS)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	rm -rf $(NAME)
	echo "MiniRT cleaned"

re: fclean all

.PHONY: all clean fclean re
