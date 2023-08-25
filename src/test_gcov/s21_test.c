#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_test_math.h"

START_TEST(test_abs) {
  int test_values[] = {
      0,       1,      -1,      123,    -456,    789,    -101112, 131415,
      -161718, 192021, -222324, 252627, -282930, 313233, -343536, 373839,
      -404142, 434445, -464748, 495051, -525354, 555657, -585960, 616263,
      -646566, 676869, -707172, 737475, -767778, 798081, -828384, 858687,
      -888990, 919293, -949596, 979899, -100};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    int x = test_values[i];
    int orig_result = abs(x);
    int s21_result = s21_abs(x);
    ck_assert_int_eq(orig_result, s21_result);
  }
}
END_TEST

START_TEST(test_fabs) {
  double test_values[] = {
      0.0,       -0.0,      1.0,      -1.0,      123.45,   -456.78,   789.01,
      -112.1314, 1315.1617, -18.1920, 21.2223,   -2.2526,  257.2829,  -28.3132,
      33.3435,   -36.3738,  339.4041, -442.4344, 45.4647,  -448.4950, 49.5253,
      -54.5556,  57.5859,   -58.6162, 61.6465,   -66.6768, 669.7071,  -772.7374,
      73.7677,   -778.7980, 081.8283, -384.8586, 687.8889, -990.9192, 913.9495,
      -96.9798,  99.100,    s21_nan,  s21_inf};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    double orig_result = fabs(x);
    double s21_result = s21_fabs(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_ceil) {
  double test_values[] = {
      2.3,         5.6,         -3.2,         -7.9,         0.0,
      1.234,       -9.876,      3.14159,      100.001,      -55.555,
      987.654,     -123.456,    0.00001,      999.99999,    123456.789,
      -987654.321, 0.123456789, -0.987654321, 1000000000.0, -1000000000.0,
      1e-10,       -1e-10,      1e-100,       -1e-100,      s21_nan,
      s21_inf};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = ceil(x);
    long double s21_result = s21_ceil(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_exp) {
  double test_values[] = {-2.0, -1.0,   0.0,     1.0,     2.0,
                          3.0,  4.0,    10.0,    -10.0,   0.5,
                          -0.5, 25.123, -10.123, s21_nan, s21_inf};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = exp(x);
    long double s21_result = s21_exp(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_fmod) {
  double test_values[][2] = {
      {-2.0, 5},          {-1.0, 3.0},        {5.0, 0.0},
      {0.0, 88},          {3241.0, 32},       {32.0, 12},
      {3.0, s21_inf},     {4.0, s21_nan},     {s21_inf, 10.0},
      {s21_nan, -10.0},   {0.5, 0.2},         {s21_inf, s21_inf},
      {s21_nan, s21_nan}, {-10.123},          {s21_inf, s21_nan},
      {s21_nan, s21_inf}, {10.0, -3.5},       {100.0, 3.5},
      {-100.0, -3.5},     {123456.789, 0.01}, {0.123, 0.01}};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double number = test_values[i][0];
    double sec_num = test_values[i][1];
    long double orig_result = fmod(number, sec_num);
    long double s21_result = s21_fmod(number, sec_num);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_floor) {
  double test_values[] = {3.7,  -2.5, 10.1,   -7.9,  0.0,     5.5,
                          -4.3, 2.0,  -1.0,   100.9, -20.7,   6.4,
                          -3.8, 8.2,  -5.0,   15.3,  -12.1,   9.9,
                          -6.6, 4.1,  -0.123, 0.123, s21_nan, s21_inf};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = floor(x);
    long double s21_result = s21_floor(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_sqrt) {
  double test_values[] = {2.543,     4.0,     16.0,   25.0,    100.0,
                          0,         -0.5,    -0.25,  -0.0625, -0.0001,
                          -0.000001, s21_nan, s21_inf};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = sqrt(x);
    long double s21_result = s21_sqrt(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_pow) {
  double test_values[][2] = {
      {2.0, 3.0},
      {1.5, 2.0},
      {-2.0, 4.0},
      {3.0, 0.0},
      {2.0, -3.0},
      {-2.0, -2.0},
      {10.0, 5.0},
      {s21_nan, s21_nan},
      {s21_nan, 4},
      {4, s21_nan},
      {7.0, -2.0},
      {s21_inf, s21_inf},
      {0.5, -1.0},
      {s21_inf, 4},
      {4, s21_inf},
      {-1.0, -1.0},
      {-2.0, -3.0},
      {s21_nan, s21_inf},
      {s21_inf, s21_nan},
      {-2.876123, -3.3333},
      {-2321312.876121323, -3253.3213333},
      {0.0, 0.0},
      {1.0, s21_nan},
      {s21_nan, 0.0},
      {0.0, s21_inf},
      {0.0, -s21_inf},
      {-s21_inf, 2},
      {-s21_inf, 3},
      {s21_inf, -s21_inf},
      {s21_inf, s21_inf},
      {s21_nan, -s21_inf},
      {s21_inf, s21_nan},
  };
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i][0];
    double y = test_values[i][1];
    long double orig_result = pow(x, y);
    long double s21_result = s21_pow(x, y);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-9);
    }
  }
}
END_TEST

START_TEST(test_log) {
  double test_values[] = {1.0,  2.0,  5.0, 10.0,    0.5,
                          0.25, -2.0, 0.0, s21_inf, s21_nan};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = log(x);
    long double s21_result = s21_log(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_sin) {
  double test_values[] = {0.0,    500,  1.0,   -500,    -1.0,   0.5,
                          -0.5,   2.0,  -2.0,  3.0,     -3.0,   0.785,
                          -0.785, 1.57, -1.57, s21_inf, s21_nan};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = sin(x);
    long double s21_result = s21_sin(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_cos) {
  double test_values[] = {0.0,    500,  1.0,   -500,    -1.0,   0.5,
                          -0.5,   2.0,  -2.0,  3.0,     -3.0,   0.785,
                          -0.785, 1.57, -1.57, s21_inf, s21_nan};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = cos(x);
    long double s21_result = s21_cos(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_tan) {
  double test_values[] = {0.0,    500,  1.0,   -500,    -1.0,   0.5,
                          -0.5,   2.0,  -2.0,  3.0,     -3.0,   0.785,
                          -0.785, 1.57, -1.57, s21_inf, s21_nan};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = tan(x);
    long double s21_result = s21_tan(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_atan) {
  double test_values[] = {0.0,   1.0,    -1.0,    12,      37.00001, -10,
                          0.5,   -0.5,   2.0,     -2.0,    3.0,      -3.0,
                          0.785, -0.785, s21_inf, s21_nan, 1.57,     -1.57};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = atan(x);
    long double s21_result = s21_atan(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_asin) {
  double test_values[] = {0.0,     0.9999, -0.123,  -100,   1.00, -0.98999,
                          0.98999, 0.5213, -1.01,   1.01,   1.0,  -1.0,
                          -0.232,  0.324,  s21_inf, s21_nan};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = asin(x);
    long double s21_result = s21_asin(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

START_TEST(test_acos) {
  double test_values[] = {0.0,  0.11123, 0.11,   -0.123,  -500,   500,
                          -1.0, 1.0,     0.5213, -1.01,   1.01,   1.0,
                          -1.0, -0.232,  0.324,  s21_inf, s21_nan};
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    long double orig_result = acos(x);
    long double s21_result = s21_acos(x);
    if (isnan(orig_result) && isnan(s21_result)) {
      ck_assert_ldouble_nan(s21_result);
    } else if (isinf(orig_result) && isinf(s21_result)) {
      ck_assert_ldouble_infinite(s21_result);
    } else {
      ck_assert_ldouble_eq_tol(orig_result, s21_result, 1e-10);
    }
  }
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite = suite_create("s21_math");

  TCase *tc_abs = tcase_create("s21_abs");
  TCase *tc_acos = tcase_create("s21_acos");
  TCase *tc_asin = tcase_create("s21_asin");
  TCase *tc_atan = tcase_create("s21_atan");
  TCase *tc_ceil = tcase_create("s21_ceil");
  TCase *tc_cos = tcase_create("s21_cos");
  TCase *tc_exp = tcase_create("s21_exp");
  TCase *tc_fabs = tcase_create("s21_fabs");
  TCase *tc_floor = tcase_create("s21_floor");
  TCase *tc_fmod = tcase_create("s21_fmod");
  TCase *tc_log = tcase_create("s21_log");
  TCase *tc_pow = tcase_create("s21_pow");
  TCase *tc_sin = tcase_create("s21_sin");
  TCase *tc_sqrt = tcase_create("s21_sqrt");
  TCase *tc_tan = tcase_create("s21_tan");

  tcase_add_test(tc_abs, test_abs);
  tcase_add_test(tc_acos, test_acos);
  tcase_add_test(tc_asin, test_asin);
  tcase_add_test(tc_atan, test_atan);
  tcase_add_test(tc_fabs, test_fabs);
  tcase_add_test(tc_ceil, test_ceil);
  tcase_add_test(tc_exp, test_exp);
  tcase_add_test(tc_fmod, test_fmod);
  tcase_add_test(tc_floor, test_floor);
  tcase_add_test(tc_sqrt, test_sqrt);
  tcase_add_test(tc_pow, test_pow);
  tcase_add_test(tc_log, test_log);
  tcase_add_test(tc_sin, test_sin);
  tcase_add_test(tc_sin, test_cos);
  tcase_add_test(tc_tan, test_tan);

  suite_add_tcase(suite, tc_abs);
  suite_add_tcase(suite, tc_fabs);
  suite_add_tcase(suite, tc_ceil);
  suite_add_tcase(suite, tc_exp);
  suite_add_tcase(suite, tc_fmod);
  suite_add_tcase(suite, tc_floor);
  suite_add_tcase(suite, tc_sqrt);
  suite_add_tcase(suite, tc_pow);
  suite_add_tcase(suite, tc_log);
  suite_add_tcase(suite, tc_sin);
  suite_add_tcase(suite, tc_cos);
  suite_add_tcase(suite, tc_tan);
  suite_add_tcase(suite, tc_atan);
  suite_add_tcase(suite, tc_asin);
  suite_add_tcase(suite, tc_acos);

  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}