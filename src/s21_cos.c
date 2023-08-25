#include "s21_math.h"

long double s21_cos(double x) {
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
  long double res = 1;
  long double expon = 2;
  long double sign = -1;
  long double temp = 1;
  while (s21_fabs(temp) > s21_EPS) {
    temp = (fast_pow(x, expon) / factorial(expon)) * sign;
    res += temp;
    expon += 2;
    sign *= -1;
  }
  return res;
}
