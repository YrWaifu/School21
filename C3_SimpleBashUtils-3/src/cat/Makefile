CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
TESTPATH = tests/test
TESTFILES = $(TESTPATH)1.txt $(TESTPATH)2.txt

all: s21_cat

s21_cat: cat.o
	$(CC) cat.o -o s21_cat

cat.o:
	$(CC) $(CFLAGS) cat.c

test: s21_cat
	bash test.sh

rebuild: clear s21_cat

clear:
	rm -rf *.o s21_cat