#include "s21_math.h"

long double s21_log(double x) {
  if (x == 0) {
    return s21_inf * (-1);
  } else if (s21_isinf(x)) {
    return s21_inf;
  } else if (s21_isnan(x)) {
    return s21_nan;
  } else if (x < 0) {
    return s21_nan * (-1);
  }
  long double result = 0;
  long double term = (x - 1) / (x + 1);
  long double term_squared = term * term;
  long double multiplier = 1;
  for (int i = 1; i <= 1000000; i += 2) {
    result += multiplier * term / i;
    multiplier *= term_squared;
  }
  return 2 * result;
}
