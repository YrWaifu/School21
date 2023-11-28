#include "../s21_math.h"

long double s21_exp(double x) {
    long double result = 1.0;
    int sign = 0;
    long double member = 1.0;
    long double i = 1.0;
    int flag = 0;

    if (x < 0) {
        x *= -1;
        sign = 1;
    }

    while ((flag == 0) && (s21_fabs(member) > s21_EPSILON)) {
        member *= x / i;
        i++;
        result += member;
        if (result > s21_MAX) {
            result = s21_INF;
            flag = 1;
        }
    }

    if (sign) {
        if (result > s21_MAX) {
            result = 0;
        } else {
            result = 1.0 / result;
        }
    }

    if (result > s21_MAX) {
        result = s21_INF;
    }

    return result;
}