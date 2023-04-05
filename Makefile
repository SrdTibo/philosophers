NAME = philosophers
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g -pthread
SRC	= 	args.c \

OBJ	= $(SRC:.c=.o)

all : 		$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean :	clean
	rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
