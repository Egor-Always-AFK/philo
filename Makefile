NAME = philo

CC = gcc

CFLAGS = -pthread

HEADER = philo.h

SRCS =  main.c init.c utils.c philo.c monitor.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS)

.PHONY: all clean fclean re norm