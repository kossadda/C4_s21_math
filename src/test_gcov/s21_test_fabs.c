#include "s21_test_math.h"

long double s21_fabs(double x) {
  if (s21_isnan(x)) {
    x = s21_nan * (-1);
  }
  return (x < 0) ? x * (-1) : x;
}