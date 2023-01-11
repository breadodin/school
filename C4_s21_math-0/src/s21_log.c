#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0, temp = 0;
  int ee = 0;
  if (x == S21_INF_POS) {
    result = x;
  } else if (x == 0) {
    result = S21_INF_NEG;
  } else if (x < 0) {
    result = S21_NAN;
  } else {
    for (; x >= S21_E; ee++) {
      x /= S21_E;
    }
    for (int i = 0; i < 100; i++) {
      temp = result;
      result = temp + 2 * (x - s21_exp(temp)) / (x + s21_exp(temp));
    }
    result += ee;
  }
  return result;
}
