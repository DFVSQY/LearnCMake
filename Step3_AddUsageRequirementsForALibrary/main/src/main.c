#include "my_math.h"
#include <stdio.h>

int main() {
    int a = 20, b = 30;

// 由于math/CMakeLists.txt文件中的MYMATH_EXPORTS宏被指定为PRIVATE了，所以该宏不会被继承指定
// 如果MYMATH_EXPORTS被指定为PUBLIC，则该宏会被继承指定
#ifdef MYMATH_EXPORTS
    printf("MYMATH_EXPORTS\n");
#endif

    int c = add_func(a, b);
    int d = sub_func(a, b);
    printf("c:%d d:%d\n", c, d);

    return 0;
}