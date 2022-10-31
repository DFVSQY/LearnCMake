#pragma once

// MSVC工具链才需要定义MYMATH_API
#ifdef MYMATH_EXPORTS
#define MYMATH_API __declspec(dllexport)
#else
#define MYMATH_API __declspec(dllimport)
#endif

double MYMATH_API my_sqrt(double x);