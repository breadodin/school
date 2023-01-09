#include "s21_math.h"

long double s21_ceil(double x) {
int integral_x;
integral_x = x + 1;
if (x < 0) {
    integral_x = x;
}
  return (long double)integral_x;
}
