CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c23 -g -Isrc/include

# Add your new C file here
SRCS = src/main.c src/custom_io.c src/commands.c
OBJS = $(SRCS:.c=.o)

TARGET = own_shell

# Tests also need commands.c so add it here too
TEST_SRCS = tests/test.c src/custom_io.c src/commands.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_TARGET = run_tests

.PHONY: all clean fclean re test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(TARGET) $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

re: fclean all
