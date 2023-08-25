#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (s21_isinf(x))
    res = s21_PI / 2;
  else
    res = s21_asin(x / (s21_sqrt(1 + x * x)));
  return res;
}