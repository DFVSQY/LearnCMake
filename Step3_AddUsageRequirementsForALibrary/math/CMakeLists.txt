add_library(mymath src/my_math.c)

# 此处采用PUBLIC指明依赖该库的target也会自动includes目录为搜索头文件目录，
# 这样依赖该target的CMakeLists.txt文件就不需要单独指明math/includes也为搜索头目录了
target_include_directories(mymath PUBLIC includes)

# 此处采用PRIVATE指明这个宏定义只在编译这个库时才定义，
# 使用该库的target不会自动继承这个宏定义，
# 如果采用PUBLIC则依赖该库的target在编译时也会定义这个宏
target_compile_definitions(mymath PRIVATE MYMATH_EXPORTS)