all: s21_grep

test: clean_test test_grep
	gcc -Wall -Werror -Werror -c -g test.c -o test.o
	gcc test.o -o test -lcheck
	./test

s21_grep.o: s21_grep.c
	gcc -Wall -Werror -Werror -c -g s21_grep.c -o s21_grep.o

s21_grep: s21_grep.o
	gcc s21_grep.o -o s21_grep

test_grep:
	./s21_grep -e ANY 1.txt >> s21_grep_test.txt
	./s21_grep -i IF 1.txt >> s21_grep_test.txt
	./s21_grep -v 3 1.txt >> s21_grep_test.txt
	./s21_grep -c the 1.txt >> s21_grep_test.txt
	./s21_grep -l the 1.txt >> s21_grep_test.txt

	./s21_grep -n 5 1.txt 2.txt >> s21_grep_test.txt
	./s21_grep -h 5 1.txt >> s21_grep_test.txt
	./s21_grep -s 5 1.txt >> s21_grep_test.txt
	./s21_grep -f 3.txt 1.txt >> s21_grep_test.txt

	./s21_grep -e ANY 1.txt 2.txt >> s21_grep_test.txt
	./s21_grep -i IF 1.txt 2.txt >> s21_grep_test.txt
	./s21_grep -v 3 1.txt 2.txt >> s21_grep_test.txt
	./s21_grep -c the 1.txt 2.txt >> s21_grep_test.txt
	./s21_grep -l the 1.txt 2.txt >> s21_grep_test.txt

	./s21_grep -n 5 1.txt 2.txt >> s21_grep_test.txt
	./s21_grep -h 5 1.txt 2.txt >> s21_grep_test.txt
	./s21_grep -s 5 1.txt 2.txt >> s21_grep_test.txt
	./s21_grep -f 3.txt 1.txt 2.txt >> s21_grep_test.txt

	grep -e ANY 1.txt >> grep_test.txt
	grep -i IF 1.txt >> grep_test.txt
	grep -v 3 1.txt >> grep_test.txt
	grep -c the 1.txt >> grep_test.txt
	grep -l the 1.txt >> grep_test.txt

	grep -n 5 1.txt 2.txt >> grep_test.txt
	grep -h 5 1.txt >> grep_test.txt
	grep -s 5 1.txt >> grep_test.txt
	grep -f 3.txt 1.txt >> grep_test.txt

	grep -e ANY 1.txt 2.txt >> grep_test.txt
	grep -i IF 1.txt 2.txt >> grep_test.txt
	grep -v 3 1.txt 2.txt >> grep_test.txt
	grep -c the 1.txt 2.txt >> grep_test.txt
	grep -l the 1.txt 2.txt >> grep_test.txt

	grep -n 5 1.txt 2.txt >> grep_test.txt
	grep -h 5 1.txt 2.txt >> grep_test.txt
	grep -s 5 1.txt 2.txt >> grep_test.txt
	grep -f 3.txt 1.txt 2.txt >> grep_test.txt


check_grep:
	cppcheck *.h *.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
	CK_FORK=no leaks --atExit -- ./test

valgrind:
	valgrind --leak-check=full ./s21_grep -t ANY 2.txt
	valgrind --leak-check=full ./s21_grep -e ANY 3.txt 2.txt
	valgrind --leak-check=full ./s21_grep -s 3 2.txt
	valgrind --leak-check=full ./s21_grep -i IF 1.txt
	valgrind --leak-check=full ./s21_grep -v 3 1.txt
	valgrind --leak-check=full ./s21_grep -c the 1.txt
	valgrind --leak-check=full ./s21_grep -l the 1.txt
	valgrind --leak-check=full ./s21_grep -n 5 1.txt
	valgrind --leak-check=full ./s21_grep -h 5 1.txt

clean_test:
	rm -rf *test.txt
	rm -rf test

clean: clean_test
	rm -rf s21_grep.o
	rm -rf s21_grep
	rm -rf a.out
	rm -rf *.o

rebuild: clean all
