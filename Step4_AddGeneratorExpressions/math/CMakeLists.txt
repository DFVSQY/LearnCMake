add_library(mymath src/my_math.c)

target_include_directories(mymath PUBLIC includes)

target_compile_definitions(mymath PRIVATE MYMATH_EXPORTS)

# 链接step_compile_flags
target_link_libraries(mymath PRIVATE step_compile_flags)