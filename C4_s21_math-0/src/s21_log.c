#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0, temp = 0;
  int ee = 0;
  for (; x >= S21_E; ee++) {
    x /= S21_E;
  }
  for (int i = 0; i < 100; i++) {
    temp = result;
    result = temp + 2 * (x - s21_exp(temp)) / (x + s21_exp(temp));
  }
  result += ee;
  return result;
}
