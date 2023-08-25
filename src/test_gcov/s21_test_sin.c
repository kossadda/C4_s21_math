#include "s21_test_math.h"

long double s21_sin(double x) {
  if (s21_isinf(x) || s21_isnan(x)) {
    return s21_nan;
  }
  x = s21_fmod(x, 2 * s21_PI);
  while (x > s21_PI) {
    x -= 2 * s21_PI;
  }
  while (x < -s21_PI) {
    x += 2 * s21_PI;
  }
  long double res = x;
  long double expon = 3;
  long double sign = -1;
  long double temp = x;
  while (s21_fabs(temp) > s21_EPS) {
    temp = ((fast_pow(x, expon)) / factorial(expon)) * (sign);
    res += temp;
    expon += 2;
    sign *= -1;
  }
  return res;
}