NAME = philo
HEAD = ./includes/philo.h
RM = rm -rf
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra -g
SRC = 	main.c 			\
		./src/valid.c	\
		./src/init.c	\
		./src/utils.c	\

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