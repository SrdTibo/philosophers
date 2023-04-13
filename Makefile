NAME = philosophers

src = check_args.c main.c utils.c create_philos.c action.c time.c

obj = $(src:.c=.o)

hd = philosophers.h

flags = -Wall -Wextra -Werror

cc = cc

all: $(NAME)

$(NAME): $(src) $(obj) $(hd)
	$(cc) $(flags) $(src) -o $(NAME)

%.o : %.c
	$(cc) $(flags) -c $< -o $@

clean:
	rm -rf $(obj) $(obj_b)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re :		fclean all

.PHONY :	all clean fclean re
