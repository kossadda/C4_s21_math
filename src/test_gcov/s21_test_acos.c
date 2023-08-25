#include "s21_test_math.h"

long double s21_acos(double x) {
  if (x > 1 || x < -1) {
    return s21_nan * (-1);
  } else if (s21_isinf(x) || s21_isnan(x)) {
    return s21_nan;
  } else {
    long double res = 0;
    if (x == 0) {
      res = s21_PI / 2;
    }
    if (x > 0) {
      res = s21_asin(s21_sqrt(1 - x * x));
    }
    if (x < 0) {
      res = s21_PI - s21_asin(s21_sqrt(1 - x * x));
    }
    return res;
  }
}
