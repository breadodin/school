#include "s21_math.h"

long double s21_cos(double x) {
  long double res;
  if (x == S21_INF_POS || x == S21_INF_NEG || S21_IS_NAN(x)) {
    res = S21_NAN;
  } else {
    res = s21_sin(S21_PI / 2 - x);
  }
  return res;
}
