#include <math.h>
#include <stdio.h>
#include "s21_math.h"

int main() {
  double x = 0.1, result;
  result = s21_exp(x);
  printf("Exponential of %.2lf = %.2lf", x, result);
  return 0;
}

long double s21_exp(double x) {
  long double result = 1;
  if (x == S21_INF_NEG) {
  result = 0;
  } else {
  long double factorial = 1;
  long long int i = 1;
  while (i < 1000) {
    result += x / factorial;
    x *= x;
    factorial *= (i + 1);
    ++i;
  }
}
  return result;
}
