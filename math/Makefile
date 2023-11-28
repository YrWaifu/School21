CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: s21_math

s21_math:
	$(CC) $(CFLAGS) main.c s21_math.c -o s21_math -lm

clean:
	rm -rf *.o s21_math

rebuild: clean s21_math
