#include "s21_math.h"

long double s21_exp(double x) {
  double sum = 0.0;
  int n = 0;
  double factorial = 1;
  double power = 1.0;
  double term;
  if (x > S21_EXP_POWER_DOUBLE_MAX) {
    sum = S21_INF_POS;
  } else if (x < S21_EXP_POWER_DOUBLE_MIN) {
    sum = 0.0;
  } else {
    do {
      term = power / factorial;
      sum += term;
      n += 1;
      power *= x;
      factorial *= n;
    } while (fabs(term) >= S21_EPSILON);
  }
  return sum;
}
