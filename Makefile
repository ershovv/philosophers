NAME = philo
HEAD = philo.h
SRC = main.c
RM = rm -rf
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra -g

.o : .c
		$(CC) $(FLAGS) -Imlx $< -o $@

$(NAME) : $(OBJ) $(HEAD)
	$(CC) -g $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean