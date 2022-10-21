cmake_minimum_required(VERSION 3.15)

project(AddALibray VERSION 1.0)

# 将库编译成动态库
set(BUILD_SHARED_LIBS ON)

# 主要是为了将输出的exe和dll放到同一个目录，
# 这样exe才能正常运行起来，否则dll不在exe的动态库搜索目录中
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Adds a subdirectory to the build
add_subdirectory(math)
add_subdirectory(main)

