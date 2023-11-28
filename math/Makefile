CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11 
CHFLAGS = -fprofile-arcs -ftest-coverage

all: clean gcov_report clean

s21_math.a: s21_math
	ar rc s21_math.a *.o
	rm *.o
	ranlib s21_math.a

s21_math: s21_math.h
	${CC} ${FLAGS} -c functions/*.c

s21_math_test.a: s21_math_test
	ar rc s21_math.a *.o
	rm *.o
	ranlib s21_math.a

s21_math_test: s21_math.h
	${CC} ${FLAGS} ${CHFLAGS} -c functions/*.c

test: s21_math_test.a s21_math_test.c
	$(CC) $(FLAGS) $(CHFLAGS) -c s21_math_test.c -lcheck -pthread -lrt
	$(CC) $(FLAGS) $(CHFLAGS) -o test *.o -Lfunctions s21_math.a -lm -lcheck -lpthread -lrt -lsubunit --coverage
	./test

main: main.c s21_math.a
	$(CC) $(FLAGS) -o main main.c s21_math.a -lm

gcov_report: test
	mkdir -p html
	gcov -b -l -p -c *.gcno 
	gcovr -o html/gcov_report.html --html --html-details
	rm *.gcno
	open html/gcov_report.html

clean:
	rm -rf html/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_main ./test ./main

rebuild: clean main