# 工程最顶部的CMakeLists.txt文件需要指定CMake的最小版本
# 用于保证运行CMake命令的CMake兼容性
cmake_minimum_required(VERSION 3.15)

# 设置工程名称和工程版本号
# 每一个工程都需要设置工程名称
# 而且需要在 cmake_minimum_required 命令之后立即调用 project 命令
project(BaseStartPoint VERSION 1.0)

# 使用C11标准
# cmake的一些特殊变量使用CMAKE_前缀，自定义的变量命名避免使用类似前缀
set(CMAKE_C_STANDARD 11)

# 强制要求使用指定的C11标准
# 具体可参考：
# https://hedzr.com/cmake/notes/cmake-06/
# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD_REQUIRED.html#prop_tgt:CXX_STANDARD_REQUIRED
set(CMAKE_C_STANDARD_REQUIRED ON)

# Copies an <input> file to an <output> file
# and substitutes variable values referenced as @VAR@ or ${VAR} in the input file content.
# Each variable reference will be replaced with the current value of the variable,
# or the empty string if the variable is not defined
# configure_file("inc/BaseStartPoint.h.in" "includes/BaseStartPoint.h")
configure_file("inc/BaseStartPoint.h.in" "includes/BaseStartPoint.h")

# 根据指定的源代码构建可执行文件
add_executable(step1 src/main.c)

# Since the configured file will be written into the project binary directory, 
# we must add that directory to the list of paths to search for include files.
# Specifies include directories to use when compiling a given target. 
# The named <target> must have been created by a command such as add_executable() or add_library() 
# and must not be an ALIAS target.
# The INTERFACE, PUBLIC and PRIVATE keywords are required to specify the scope of the following arguments. 
# PRIVATE and PUBLIC items will populate the INCLUDE_DIRECTORIES property of <target>. 
# PUBLIC and INTERFACE items will populate the INTERFACE_INCLUDE_DIRECTORIES property of <target>.
target_include_directories(step1 PUBLIC "${PROJECT_BINARY_DIR}/includes")