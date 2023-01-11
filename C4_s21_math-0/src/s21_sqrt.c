#include "s21_math.h"

long double s21_sqrt(double x) {
  double res;
  if (x == S21_INF_POS || x == 0) {
    res = (long double)x;
  } else if (S21_IS_NAN(x) || x == S21_INF_NEG || x < 0) {
    res = S21_NAN;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}
