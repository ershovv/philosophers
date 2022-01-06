NAME = philo
NAME_BONUS = philo_bonus
HEAD = ./includes/philo.h
RM = rm -rf
CC = gcc
LDFLAGS = -pthread
OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra -g
SRC = 	./src/main.c	\
		./src/valid.c	\
		./src/init.c	\
		./src/utils.c	\
		./src/start.c

SRC_BONUS = ./src/main.c	\
			./bonus/valid.c	\
			./bonus/init.c	\
			./bonus/utils.c	\
			./bonus/start.c

all : $(NAME)

.c : .o
	$(CC) $(CFLAGS) -c -I$(HEAD) $< -o $(<:.c=.o)

$(NAME) : $(OBJ) $(HEAD)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

bonus : $(OBJ_BONUS) $(HEAD)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all re clean fclean bonus