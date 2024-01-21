NAME = philo

SRCS = main.c parsing.c error_handle.c init_philo.c\
	   utils.c mtx_thread_error.c message.c monitor.c\
	   routine.c set_get.c sync_utils.c\

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft -g3 -fsanitize=address

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re