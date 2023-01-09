#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include "math.h"

long double s21_sin(double x);

int main() {
    double x, z;

    printf("Enter x\n");
    scanf("%lf", &x);
    z=sin(x);
    printf("%lf", z);
    return 0;
}

long double s21_fabs(double x) {
    if (x < 0) { x = -x; }
    return x;
}

long double s21_sin(double x) {
double result = x;
double term = x;
int i = 1;
int sign = 1;

while (s21_fabs(term) > 1e-15) {
term = -term * x * x / ((2 * i + 1) * (2 * i));
result += term * sign;
sign = -sign;
i++;
}

return result;
}