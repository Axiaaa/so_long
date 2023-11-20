NAME = libft.a
NAME_BONUS = libftbonus.a
CC =cc 
SRC =   ./objs/ft_atoi.c ./objs/ft_bzero.c ./objs/ft_isalnum.c ./objs/ft_isalpha.c ./objs/ft_isascii.c ./objs/ft_isdigit.c \
		./objs/ft_isprint.c ./objs/ft_itoa.c ./objs/ft_memset.c ./objs/ft_putchar_fd.c \
		./objs/ft_putendl_fd.c ./objs/ft_putnbr_fd.c ./objs/ft_strchr.c ./objs/ft_striteri.c \
		./objs/ft_putstr_fd.c ./objs/ft_strdup.c ./objs/ft_strjoin.c ./objs/ft_strlcat.c ./objs/ft_strlcpy.c ./objs/ft_strlen.c \
		./objs/ft_strmapi.c ./objs/ft_strncmp.c ./objs/ft_strnstr.c ./objs/ft_strrchr.c ./objs/ft_strtrim.c ./objs/ft_substr.c \
		./objs/ft_tolower.c ./objs/ft_toupper.c ./objs/ft_calloc.c ./objs/ft_memchr.c ./objs/ft_memcmp.c \
		./objs/ft_memcpy.c ./objs/ft_memmove.c ./objs/ft_split.c
SRC_BONUS =	./objs/ft_lstadd_back_bonus.c ./objs/ft_lstadd_front_bonus.c ./objs/ft_lstclear_bonus.c ./objs/ft_lstdelone_bonus.c \
			./objs/ft_lstiter_bonus.c ./objs/ft_lstlast_bonus.c ./objs/ft_lstmap_bonus.c ./objs/ft_lstnew_bonus.c ./objs/ft_lstsize_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
DIR = ./objs
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)


$(DIR)/%.o: %.c | $(DIR)
	$(CC) $(FLAGS) -I. -c $< -o $@

%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

$(DIR):
	mkdir -p $(DIR)

$(OBJ): $(HEADER)

$(OBJ_BONUS): $(HEADER)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME_BONUS) $(OBJ) $(OBJ_BONUS)
	@cp $(NAME_BONUS) $(NAME)

clean:
	rm -rf $(DIR)
	rm -rf $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

