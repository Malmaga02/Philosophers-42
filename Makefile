NAME = philo

CC = cc
CFLAGS = -Wextra -Werror -Wall -g  -pthread
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =	./main.c \
		./actions.c \
		./destroy.c \
		./init.c \
		./print.c \
		./room_routine.c \
		./routine.c \
		./utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I. $(OBJ) -o $(NAME)
	@echo "$(GREEN)	Philo has been compiled. $(RESET)"
	@echo "$(BLUE)	Run ./philo with [nbr_of_philos] [time_to_die] [time_to_eat] [time_to_sleep] and, if you want, [must_eat]. $(RESET)"

RM = rm -f

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "$(BLUE)	 Philo has been removed. $(RESET)"

re: fclean all