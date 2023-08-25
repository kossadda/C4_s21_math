#include "s21_test_math.h"

long double s21_fmod(double x, double y) {
  if (y == 0.0 || s21_isinf(x) || s21_isnan(x)) {
    return s21_nan;
  } else if (s21_isinf(y)) {
    return x;
  }
  long double normalized_y = (y < 0) ? -y : y;
  long double result = x - normalized_y * s21_floor(x / normalized_y);
  if (x < 0 && result > 0) {
    result -= normalized_y;
  }
  return result;
}