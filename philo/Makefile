NAME = philo

define HEADER
__________.__    .__.__
\______   \  |__ |__|  |   ____
 |     ___/  |  \|  |  |  /  _ \\
 |    |   |   Y  \  |  |_(  <_> )
 |____|   |___|  /__|____/\____/
               \/
endef
export HEADER

CC = gcc
CFLAGS = -g

SRC =	main.c	lists.c \
		ft_atoi.c	philo.c

SRC_OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) -o $(NAME)
	@echo "$$HEADER"
	@echo "philo Compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SRC_OBJS)
	@echo "Cleared philo .o and .a files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleared philo executable"

re: clean all

.PHONY: all clean fclean re