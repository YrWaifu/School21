#include "../s21_math.h"

long double s21_atan(double x) {
    long double result = 0;

    if (s21_isnan(x)) {
        result = s21_NAN;
    } else if (x == 1 || x == -1 || x == 0) {
        result = (x == 0) ? 0 : (x == 1) ? s21_PI / 4 : -s21_PI / 4;
    } else if (x > 1 || x < -1) {
        result = x > 1 ? s21_PI / 2 - basic_atan(1 / x) : -s21_PI / 2 - basic_atan(1 / x);
    } else {
        result = basic_atan(x);
    }
    
    return result;
}

long double basic_atan(double x) {
    long double result = 0;
    double arg = x;

    for (int count = 1; s21_fabs(arg) > s21_EPSILON; count++) {
        result += arg;
        arg = -1 * arg * x * x * (2 * count - 1) / (2 * count + 1);
    }

    return result;
}