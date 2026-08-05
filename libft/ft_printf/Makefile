CC = cc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
NAME =libftprintf.a
SRC_PF = ft_printf.c \
	src/ft_utils.c\
	src/ft_utils2.c
OBJ_PF = $(SRC_PF:.c=.o)
SRC_LIB =	libft/ft_strlen.c \
			libft/ft_toupper.c \
			libft/ft_isprint.c \
			libft/ft_isalnum.c \
			libft/ft_isdigit.c \
			libft/ft_isalpha.c
OBJ_LIB = $(SRC_LIB:libft/%.c=libft/%.o)

all: $(NAME)

$(NAME): $(OBJ_PF) $(OBJ_LIB)
	ar $(ARFLAGS) $(NAME) $(OBJ_PF) $(OBJ_LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ_PF) $(OBJ_LIB)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re:  fclean all