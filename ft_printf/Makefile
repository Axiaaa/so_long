NAME = libftprintf.a
CC = cc
SRC_PRINTF = ft_printf.c print_functions.c print_ptr.c
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ_PRINTF)
	ar rcs $(NAME) $(OBJ_PRINTF) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_PRINTF): $(HEADER)

clean:
	rm -rf $(DIR)
	make -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all

.PHONY : all clean fclean re