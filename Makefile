NAME = philo
HEAD = ./includes/philo.h
RM = rm
CC = gcc
LDFLAGS = -pthread
OBJ = $(SRC:%.c=%.o)
# CFLAGS = -Wall -Werror -Wextra -g
SRC = 	main.c 			\
		./src/valid.c	\
		./src/init.c	\
		./src/utils.c	\
		./src/start.c   \

.o : .c
		$(CC) -Imlx $< -o $@

$(NAME) : $(OBJ) $(HEAD)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) ./*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean