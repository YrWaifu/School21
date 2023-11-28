#include "../s21_math.h"

long double s21_floor(double x) {
    long double result = x;
    int isInf = 0;
    int intPart = x;

    if (s21_isinf(x) || s21_isnan(x)) {
        isInf = 1;
    }
    if (x < 0 && x != intPart) {
        --intPart;
    }

    return (isInf) ? result : intPart;
}