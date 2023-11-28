#include "../s21_math.h"

long double s21_cos(double x) {
    x = s21_fmod(x, s21_TWO_PI);
    long double member = x;
    long double result = x;

    if (s21_fabs(x) < s21_EPSILON) {
        result = 1.0;
    } else {
        for (int i = 0; s21_fabs(member) > s21_EPSILON && i < 100; ++i) {
            member *= ((-1.) * x * x / (2. * i * (2. * i - 1.)));
            result += member;
        }
    }

    return result;
}