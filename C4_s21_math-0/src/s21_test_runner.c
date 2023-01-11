#include <math.h>

#include "s21_math.h"

int main() {
  double base, exp, z, z2, x, y;

  printf("\nTesting: ");
  scanf("%lf", &x);
  z = asin(x);
  z2 = s21_asin(x);
  printf("\nmath.h: %lf\n\n", z);
  printf("s21_.h: %lf\n\n", z2);
  return 0;
}

long double s21_asin(double x) { return 1 / s21_sin(x); }

long double s21_cos(double x) {
  long double res = S21_NAN;
  if (x != S21_INF_POS || x != S21_INF_NEG || !S21_IS_NAN(x))
    res = s21_sin(S21_PI / 2 - x);
  return res;
}

long double s21_sin(double x) {
  long double res = 0;
  if (x == S21_INF_POS || x == S21_INF_NEG || S21_IS_NAN(x)) {
    res = S21_NAN;
  } else if (x == S21_PI) {
    res = S21_EPSILON;
  } else if (x == -S21_PI) {
    res = -S21_EPSILON;
  } else {
    if (x > 2 * S21_PI || x < -2 * S21_PI) x = s21_fmod(x, 2 * S21_PI);
    double stored_x = x;
    int i = 1;
    do {
      res += stored_x;
      stored_x *= -x * x / (2 * i * (2 * i + 1));
      i++;
    } while (s21_fabs(stored_x) > S21_EPSILON);
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res;
  if (S21_ARE_NAN(x, y)) {
    res = S21_NAN;
  } else if (S21_IS_INF(y)) {
    res = (long double)x;
  } else {
    int integral_res = x / y;
    res = (long double)x - integral_res * (long double)y;
  }
  return res;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double s21_tan(double x) {
  long double res;
  res = s21_sin(x) / s21_cos(x);
  return res;
}
