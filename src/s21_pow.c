#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 0;
  if (base == 1 || exp == 0) {
    res = 1;
  } else if (s21_isnan(base) || s21_isnan(exp)) {
    res = s21_nan;
  } else if (exp == -s21_inf && base == 0) {
    res = s21_inf;
  } else if (exp == -s21_inf || base == 0) {
    res = 0;
  } else if (exp == s21_inf) {
    res = s21_inf;
  } else if (base == s21_inf) {
    res = base;
  } else if (base == -s21_inf) {
    if (s21_fmod(exp, 2) == 0) {
      res = s21_inf;
    } else {
      res = -s21_inf;
    }
  } else if (base < 0) {
    if (s21_fabs(exp - (int)exp) > 0.0000000001) {
      res = s21_nan;
    } else {
      base = -base;
      int flag = exp < 0;
      if (exp < 0) {
        exp = -exp;
      }
      res = s21_exp(exp * s21_log(base));
      if (s21_fmod(exp, 2) != 0) {
        res = -res;
      }
      if (flag) {
        res = 1. / res;
      }
    }
  } else {
    res = s21_exp(exp * s21_log(base));
  }
  return res;
}
