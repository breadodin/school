#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <stdio.h>
#include <limits.h>

#define S21_E 2.71828182845904523536028747
#define S21_PI 3.14159265358979323846
#define S21_EPSILON 1e-17
#define S21_LN10 2.30258509299404590109
#define S21_NAN 0.0 / 0.0
#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_NEG || x == S21_INF_POS)

#define EXP_POWER_DOUBLE_MAX 709.7827
#define EXP_POWER_DOUBLE_MIN -708.3964

int s21_abs(int x);  //  модуль числа   DONE
long double s21_fabs(double x);  //  модуль с плавающей точкой DONE

long double s21_pow(double base, double exp);  //  степень
long double s21_sqrt(double x);  //  корень
long double s21_exp(double x);  //  е возведенное в заданную степень DONE (FIX NEEDED)
long double s21_log(double x);  //  логарифм

long double s21_sin(double x);  //  синус
long double s21_cos(double x);  //  косинус
long double s21_tan(double x);  //  тангенс

long double s21_asin(double x);  //  арксинус
long double s21_acos(double x);  //  арккосинус
long double s21_atan(double x);  //  арктангенс

long double s21_floor(double x);  //  ближайшее целое число (не больше) DONE and FIXED
long double s21_ceil(double x);  //  ближайшее целое число (не меньше) DONE and FIXED

long double s21_fmod(double x, double y);  //  остаток деления с плавающей точкой






#endif  // S21_MATH_H_
