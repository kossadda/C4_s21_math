#include "s21_math.h"

long double factorial(double n) {
  long double result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double fast_pow(double base, int exp) {
  double result = 1.0;
  double current_pow = base;
  int abs_exp = (exp < 0) ? -exp : exp;
  while (abs_exp > 0) {
    if (abs_exp % 2 == 1) {
      result *= current_pow;
    }
    current_pow *= current_pow;
    abs_exp /= 2;
  }
  return result;
}