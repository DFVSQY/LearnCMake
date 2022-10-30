add_library(mymath src/my_math.c)

target_include_directories(mymath PUBLIC includes)

target_compile_definitions(mymath PRIVATE MYMATH_EXPORTS)

# Load and run CMake code from a file or module.
# Check if given C source compiles and links into an executable.
include(CheckCSourceCompiles)

check_c_source_compiles("
#include<math.h>
int main(){
	pow(1, 2);
	return 0;
}
" HAS_MATH_POW)

if(HAS_MATH_POW)
	target_compile_definitions(mymath PRIVATE "HAS_MATH_POW")
endif()