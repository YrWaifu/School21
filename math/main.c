#include <math.h>
#include <stdio.h>

#include "s21_math.h"

// убрать в мейке -lm, убрать инклюд матх.х
// разорабть метод ньюотна в подсчете логарифма

int main() {
    double number = 0.5;

    printf("%f\n", cos(number));
    printf("%Lf", s21_cos(number));
}