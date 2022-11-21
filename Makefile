CFLAGS = -Wall -Werror -Wextra

all: s21_cat
	
s21_cat: s21_cat.c
	gcc -c $(CFLAGS) s21_cat.c -o s21_cat.o
	gcc $(CFLAGS) s21_cat.o -o s21_cat

rebuild:
	make clean
	make all

clean:
	rm -rf ./*.o s21_cat
