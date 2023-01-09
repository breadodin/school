#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <stdio.h>
#include <limits.h>

#define S21_E 2.71828182845904523536028747
#define S21_PI 3.14159265358979323846

int s21_abs(int x);  //  модуль числа   DONE
long double s21_fabs(double x);  //  модуль с плавающей точкой DONE

long double s21_pow(double base, double exp);  //  степень
long double s21_sqrt(double x);  //  корень
long double s21_exp(double x);  //  е возведенное в заданную степень

long double s21_sin(double x);  //  синус
long double s21_cos(double x);  //  косинус
long double s21_tan(double x);  //  тангенс

long double s21_asin(double x);  //  арксинус
long double s21_acos(double x);  //  арккосинус
long double s21_atan(double x);  //  арктангенс

long double s21_floor(double x);  //  ближайшее целое число (не больше) DONE
long double s21_ceil(double x);  //  ближайшее целое число (не меньше) DONE

long double s21_fmod(double x, double y);  //  остаток деления с плавающей точкой
long double s21_log(double x);  //  логарифм





#endif  // S21_MATH_H_
