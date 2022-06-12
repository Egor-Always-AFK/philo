NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra
HEADER = philo.h

SRCS =  init.c main.c utils.c philo.c monitor.c check.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS)

.PHONY: all clean fclean re norm