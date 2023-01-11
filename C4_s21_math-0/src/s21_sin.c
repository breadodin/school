#include "S21_math.h"

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
