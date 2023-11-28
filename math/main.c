#include <math.h>
#include <stdio.h>

#include "s21_math.h"

// убрать в мейке -lm, убрать инклюд матх.х
// разорабть метод ньюотна в подсчете логарифма

int main() {
    double number = -1.3;

    printf("Ceil of %lf is %Lf\n", number, s21_ceil(number));
    printf("Ceil of %lf is %f\n", number, ceil(number));
}