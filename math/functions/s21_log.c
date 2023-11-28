#include "../s21_math.h"

long double s21_log(double x) {
    int countE = 0;
    long double result = 0.0;
    double prevResult = 0.0;

    if (x == s21_INF) {
        result = s21_INF;
    } else if (x == 0) {
        result = -s21_INF;
    } else if (x < 0) {
        result = s21_NAN;
    } else if (x == 1) {
        result = 0;
    } else {
        while (x >= s21_EXP) {
            x /= s21_EXP;
            ++countE;
        }

        for (int i = 0; i < 100; ++i) {
            prevResult = result;
            result = prevResult + 2 * (x - s21_exp(prevResult)) / (x + s21_exp(prevResult));
        }
    }

    return countE + result;
}