#include "s21_math.h"

long double s21_floor(double x) {
int integral_x;
integral_x = x;
if (x < 0) {
    integral_x = x - 1;
}
  return (long double)integral_x;
}
