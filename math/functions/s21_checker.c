#include "../s21_math.h"

int s21_isinf(double x) { return (x == x + 1) ? 1 : 0; }

int s21_isnan(double x) { return x != x; }