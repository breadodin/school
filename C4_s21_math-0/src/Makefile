CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))

all: $(OBJECTS) s21_tests
	$(MAKE) clean
	clear

s21_tests: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) ./Tests/s21_math_tests.c -o ./s21_test

.c.o: $(OBJECTS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

rebuild:
	$(MAKE) clean
	$(MAKE) all
