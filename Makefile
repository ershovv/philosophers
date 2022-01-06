NAME = philo
HEAD = ./includes/philo.h
RM = rm -rf
CC = gcc
LDFLAGS = -pthread
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra -g
SRC = 	main.c 			\
		./src/valid.c	\
		./src/init.c	\
		./src/utils.c	\
		./src/start.c   \

all : $(NAME)

.c : .o
	$(CC) $(CFLAGS) -c -I$(HEAD) $< -o $(<:.c=.o)

$(NAME) : $(OBJ) $(HEAD)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean