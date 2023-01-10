#include "s21_math.h"

long double s21_ceil(double x) {
int integral_x;
if (S21_IS_NAN(x) || S21_IS_INF(x)) {
  integral_x = x;
} else {
integral_x = x;
if (integral_x < x) {
  integral_x = integral_x + 1;
}
if (x < 0) {
    integral_x = x;
}
}
  return (long double)integral_x;
}
