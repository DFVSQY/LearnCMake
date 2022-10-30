#pragma once

// MSVC工具链才需要定义MYMATH_API
#ifdef MYMATH_EXPORTS
#define MYMATH_API __declspec(dllexport)
#else
#define MYMATH_API __declspec(dllimport)
#endif

int MYMATH_API add_func(int a, int b);

int MYMATH_API sub_func(int a, int b);

int MYMATH_API pow_func(double x, double y);