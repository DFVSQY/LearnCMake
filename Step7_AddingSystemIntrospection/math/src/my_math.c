#include "my_math.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

int add_func(int a, int b) { return a + b; }

int sub_func(int a, int b) { return a - b; }

int pow_func(double a, double b) {
#ifdef HAS_MATH_POW
    return pow(a, b);
#else
    printf("this system doesn't support pow function!\n");
    return -1;
#endif
}