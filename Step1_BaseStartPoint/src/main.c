#include "BaseStartPoint.h"
#include <stdio.h>

    // C11新增的匿名结构体支持
    struct person {
    char *name;
    int age;
    struct {
        int area_code;
        long phone_number;
    };
};

int main() {
    printf("hello world\n");

    struct person bill = {"Bill", 20, {21, 10086}};
    printf("bill age:%d\n", bill.age);

    printf("BaseStartPoint_VERSION_MAJOR:%d\n", BaseStartPoint_VERSION_MAJOR);
    printf("BaseStartPoint_VERSION_MINOR:%d\n", BaseStartPoint_VERSION_MINOR);

    return 0;
}