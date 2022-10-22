#include "AddALibrary.h"
#ifdef USE_MYMATH
#include "my_math.h"
#endif
#include <stdio.h>

int main() {
    printf("visual studio code\n");

    int a = 10, b = 20;
#ifdef USE_MYMATH
    int c = add_func(a, b);
    int d = sub_func(a, b);
#else
    int c = 0;// a + b;
    int d = 0;// a - b;
#endif
    printf("c:%d d:%d\n", c, d);

    printf("hello world\n");

    return 0;
}