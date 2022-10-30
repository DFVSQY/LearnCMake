cmake_minimum_required(VERSION 3.15)

project(AddGeneratorExpressions VERSION 1.0)

# 移除这两行
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_C_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_options(-W3 -WX)

# 设置gcc和msvc样式编译器的变量
# $<COMPILE_LANG_AND_ID:language,compiler_ids>
# https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#genex:COMPILE_LANG_AND_ID
set(gcc_like_c "$<COMPILE_LANG_AND_ID:C,Clang,GNU>")
set(msvc_c "$<COMPILE_LANG_AND_ID:C,MSVC>")

# 创建step_compile_flags
add_library(step_compile_flags INTERFACE)

# 设置step_compile_flags 编译选项
# We only want these warning flags to be used during builds.
# Consumers of our installed project should not inherit our warning flags.
# To specify this, we wrap our flags in a generator expression using the BUILD_INTERFACE condition
target_compile_options(step_compile_flags INTERFACE
	"$<${gcc_like_c}:$<BUILD_INTERFACE:-Wall;-Werror>>"
	"$<${msvc_c}:$<BUILD_INTERFACE:-Wall;-WX>>"
)

# 在目标上调用target_compile_features函数将检查传入的功能，
# 并由CMake确定正确的用于目标的编译器标志。
target_compile_features(step_compile_flags INTERFACE c_std_11)

add_subdirectory(math)
add_subdirectory(main)