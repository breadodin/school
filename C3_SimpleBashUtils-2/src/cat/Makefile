all: s21_cat

test: clean_test test_cat
	gcc -Wall -Werror -Werror -c test.c -o test.o
	gcc test.o -o test -lcheck
	./test

s21_cat.o: s21_cat.c
	gcc -Wall -Werror -Werror -c -g s21_cat.c -o s21_cat.o

s21_cat: s21_cat.o
	gcc s21_cat.o -o s21_cat

test_cat:
	./s21_cat -b 1.txt >> s21_cat_test.txt
	./s21_cat -n 1.txt >> s21_cat_test.txt
	./s21_cat -s 1.txt >> s21_cat_test.txt
	./s21_cat -t 2.txt >> s21_cat_test.txt
	./s21_cat -e 1.txt >> s21_cat_test.txt

	./s21_cat --number-nonblank -n 1.txt >> s21_cat_test.txt
	./s21_cat --squeeze-blank --number 1.txt >> s21_cat_test.txt
	./s21_cat -t -n 2.txt >> s21_cat_test.txt
	./s21_cat -E -n 1.txt >> s21_cat_test.txt


	./s21_cat --squeeze-blank -b 1.txt >> s21_cat_test.txt
	./s21_cat -T -b 1.txt >> s21_cat_test.txt
	./s21_cat -e -b 1.txt >> s21_cat_test.txt

	
	./s21_cat -t -s 2.txt >> s21_cat_test.txt
	./s21_cat -e -s 1.txt >> s21_cat_test.txt

	cat -b 1.txt >> cat_test.txt
	cat -n 1.txt >> cat_test.txt
	cat -s 1.txt >> cat_test.txt
	cat -t 2.txt >> cat_test.txt
	cat -e 1.txt >> cat_test.txt

	cat -b -n 1.txt >> cat_test.txt
	cat -s -n 1.txt >> cat_test.txt
	cat -t -n 2.txt >> cat_test.txt
	cat -e -n 1.txt >> cat_test.txt


	cat -s -b 1.txt >> cat_test.txt
	cat -t -b 1.txt >> cat_test.txt
	cat -e -b 1.txt >> cat_test.txt

	
	cat -t -s 2.txt >> cat_test.txt
	cat -e -s 1.txt >> cat_test.txt

check_cat:
	cppcheck *.h *.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
	CK_FORK=no leaks --atExit -- ./test

valgrind:
	valgrind --leak-check=full ./s21_cat -t -s 2.txt

clean_test:
	rm -rf *test.txt
	rm -rf test

clean: clean_test
	rm -rf s21_cat.o
	rm -rf s21_cat
	rm -rf a.out
	rm -rf *.o

rebuild: clean all
