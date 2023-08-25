#include "s21_test_math.h"

long double s21_ceil(double x) {
  if (s21_isnan(x)) {
    return s21_nan;
  } else if (s21_isinf(x)) {
    return s21_inf;
  }
  if (x >= 0) {
    if (x == (int)x) {
      x = (int)x;
    } else {
      x = (int)x + 1;
    }
  } else {
    x = (int)x;
    if (x == 0) {
      x = s21_negative0;
    }
  }
  return x;
}