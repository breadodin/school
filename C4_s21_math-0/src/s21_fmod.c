#include "s21_math.h"

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
