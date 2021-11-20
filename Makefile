NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = check_funks.c controls.c pre_process.c \
	main.c sort.c libft/libft.a

all:
	$(CC) $(CFLAGS) $(SRCS)