CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
TESTPATH = tests/
TESTFILES = $(TESTPATH)test1.txt $(TESTPATH)test2.txt

all: s21_grep

s21_grep: grep.o
	$(CC) grep.o -o s21_grep -lpcre

grep.o:
	$(CC) $(CFLAGS) grep.c -lpcre

rebuild: clear s21_grep

test: s21_grep
	bash test.sh

clear:
	rm -rf *.o s21_grep