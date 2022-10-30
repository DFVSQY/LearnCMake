#include "my_math.h"
#include <stdio.h>

int main(void) {
    int a = 20, b = 30;

    int c = add_func(a, b);
    int d = sub_func(a, b);
    printf("c:%d d:%d\n", c, d);

    long len = 20;
    printf("len:%d\n", len);

    return 0;
}