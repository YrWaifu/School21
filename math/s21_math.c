#include "s21_math.h"

long double s21_ceil(double x) {
    long double result = 0.0;
    long long int intPart = (long long int)x;

    if (x >= 0) {
        result = (x > intPart) ? (intPart + 1) : x;
    } else {
        result = (x < intPart) ? (intPart + 1) : x;
    }

    return result;
}