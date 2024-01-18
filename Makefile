NAME = so_long
LIBFT = ./libft
FT_PRINTF = ./libft/ft_printf
GET_NEXT_LINE = ./libft/get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = ./mlx_linux


SRC =	srcs/main.c 		\
		srcs/parsing.c		\
		srcs/check_map.c 	\
		srcs/init_map.c 	\
		srcs/input.c 		\
		srcs/tiles.c 		\
		srcs/utils.c 		\
		srcs/utils2.c 		\

OBJ = $(SRC:.c=.o)
HEADERS = inc/so_long.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) 
	@make -C $(LIBFT)
	@make -C $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Iinc ./libft/Libft.a ./mlx_linux/libmlx.a -L $(MLX) -lXext -lX11
	@echo "Compilation done"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re