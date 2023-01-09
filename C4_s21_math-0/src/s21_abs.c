#include "s21_math.h"

int s21_abs(int x) {
    int result = x;
    if (x < 0 && x > INT_MIN) {
        result = -x;
    }
    return result;
}
