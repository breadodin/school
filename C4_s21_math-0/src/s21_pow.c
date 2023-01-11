#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res;
  if (!exp) {
    res = 1;
  } else if (base == S21_INF_NEG && exp == S21_INF_NEG) {
    res = 0;
  } else if (base == S21_INF_NEG && exp == S21_INF_POS) {
    res = S21_INF_POS;
  } else if (base < 0 && exp != (long long int)exp) {
    res = S21_NAN;
  } else {
    res = s21_exp(exp * s21_log(base));
  }
  return res;
}
