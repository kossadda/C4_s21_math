#include "s21_math.h"

long double s21_sqrt(double x) {
  if (x < 0 || s21_isnan(x)) {
    return s21_nan;
  } else if (s21_isinf(x)) {
    return s21_inf;
  }
  long double guess = x;
  long double estimate = 0;
  while (s21_fabs(guess - estimate) > s21_EPS) {
    estimate = guess;
    guess = (x / estimate + estimate) / 2;
  }
  return guess;
}
