#include "my_math.h"
#include <stdio.h>

int main(void) {
    int a = 20, b = 30;

    int c = add_func(a, b);
    int d = sub_func(a, b);
    printf("c:%d d:%d\n", c, d);

    double x = 10, y = 2;
    double z = pow_func(x, y);
    printf("z:%f\n", z);

    return 0;
}