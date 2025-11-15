CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c23 -g

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

TARGET = own_shell

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
