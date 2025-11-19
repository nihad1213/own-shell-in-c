CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c23 -g -Isrc/include

SRCS = src/main.c src/custom_io.c
OBJS = $(SRCS:.c=.o)

TARGET = own_shell

TEST_SRCS = tests/test.c src/custom_io.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_TARGET = run_tests

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

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

re: fclean all
