#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdbool.h>
#include <stdio.h>

#define s21_isnan(X) ((X) != (X))
#define s21_isinf(X) ((X) == (1.0 / 0.0))
#define s21_nan 0.0 / 0.0
#define s21_inf 1.0 / 0.0
#define s21_PI 3.141592653589793
#define s21_EPS 1e-100
#define s21_negative0 -0.0
long double factorial(double x);
double fast_pow(double base, int exp);

// 1. Вычисляет абсолютное значение целого числа
int s21_abs(int x);

// 2. Вычисляет арккосинус
long double s21_acos(double x);

// 3. Вычисляет арксинус
long double s21_asin(double x);

// 4. Вычисляет арктангенс
long double s21_atan(double x);

// 5. Возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x);

// 6. Вычисляет косинус
long double s21_cos(double x);

// 7. Возвращает значение e, возведенное в заданную степень
long double s21_exp(double x);

// 8. Вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x);

// 9. Возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x);

// 10. Остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y);

// 11. Вычисляет натуральный логарифм
long double s21_log(double x);

// 12. Возводит число в заданную степень
long double s21_pow(double base, double exp);

// 13. Вычисляет синус
long double s21_sin(double x);

// 14. Вычисляет квадратный корень
long double s21_sqrt(double x);

// 15. Вычисляет тангенс
long double s21_tan(double x);

#endif