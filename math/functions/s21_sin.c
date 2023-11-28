#include "../s21_math.h"

long double s21_sin(double x) {
    x = s21_fmod(x, s21_TWO_PI);
    long double member = x;
    long double result = x;

    if (s21_fabs(x) < s21_EPSILON) {
        result = 0.0;
    } else {
        for (int i = 1; s21_fabs(member) > s21_EPSILON && i < 100; i++) {
            member *= ((-1.0) * x * x / (2.0 * i * (2.0 * i + 1.0)));
            result += member;
        }
    }

    return result;
}