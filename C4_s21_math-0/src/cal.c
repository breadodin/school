#include <math.h>

#include "s21_math.h"

int main() {
  double x, z, z2;

  printf("\nTesting: ");
  scanf("%lf", &x);
  z = exp(x);
  z2 = s21_exp(x);
  printf("\nmath.h: %lf\n\n", z);
  printf("s21_.h: %lf\n\n", z2);
  return 0;
}

long double s21_exp(double x) {
  long double result = 1;
  long double factorial = 1;
  long long int i = 1;
  if (x > EXP_POWER_DOUBLE_MAX) {
        result = S21_INF_POS;
    } else if (x < EXP_POWER_DOUBLE_MIN) {
        result = 0.0;
    } else {
  while (i < 1000) {
    result += x / factorial;
    x *= x;
    factorial *= (i + 1);
    ++i;
  }
}
  return result;
}



















long double s21_log(double x) {
  int i = 2;
  long double result = x - 1;
  long double stored_res = result, stored_x = x;
if (x < (2.0 + S21_EPSILON)) {
    x = (x - 1);

    while (s21_fabs(stored_res / i) > S21_EPSILON) {
      stored_res *= (-1 * x);
      result += (stored_res / i);
      i += 1;
    }
  } else {
    int k = 0;
    while (stored_x > 1.0) {
      stored_x /= 10;
      k++;
    }
    result = (s21_log(stored_x) + k * S21_LN10);
  }
  return result;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}
