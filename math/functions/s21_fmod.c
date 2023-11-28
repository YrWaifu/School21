#include "../s21_math.h"

long double s21_fmod(double x, double y) {
    long double result = x;

    if (s21_isinf(x) || s21_isnan(x) || s21_isnan(y) || y == 0.0 || y == -0.0) {
        result = s21_NAN;
    } else if (s21_isinf(y)) {
        result = x;
    } else if (x == 0.0 || x == -0.0) {
        result = 0.0;
    } else {
        long double quo = x / y;
        long double intPart = (long long)quo;
        result = x - intPart * y;
    }

    return result;
}