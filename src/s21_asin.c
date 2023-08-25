#include "s21_math.h"

long double s21_asin(double x) {
  if (x > 1 || x < -1) {
    return s21_nan * (-1);
  } else if (s21_isinf(x) || s21_isnan(x)) {
    return s21_nan;
  }
  long double res = x;
  long double temp = x;
  long double num_den = 1;
  if (x == 1)
    res = s21_PI / 2;
  else if (x == -1)
    res = s21_PI / -2;
  else {
    for (long double expon = 3, num = 1, denom = 2; s21_fabs(temp) > s21_EPS;
         expon += 2, num += 2, denom += 2) {
      num_den *= num / denom;
      temp = num_den * (fast_pow(x, (int)expon) / expon);
      res += temp;
      if (num > 1000000) {
        temp = s21_EPS / 10;
      }
    }
  }
  return res;
}