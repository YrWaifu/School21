#include "../s21_math.h"

long double s21_pow(double base, double exp) {
    long double result = 0.0;
    long double member = base;

    if (exp == 0) {
        result = 1.0;
    } else if (base == 1) {
        result = 1.0;
    } else if (base == s21_INF || (base == -s21_INF && s21_fmod(exp, 2) == 0)) {
        result = s21_INF;
    } else if (base < 0 && (long long int)exp != exp) {
        result = s21_NAN;
    } else if (member < 0) {
        member = -member;
        result = s21_exp(exp * s21_log(member));
        if (s21_fmod(exp, 2) != 0) {
            result = -result;
        }
    } else {
        result = s21_exp(exp * s21_log(base));
    }

    return result;
}