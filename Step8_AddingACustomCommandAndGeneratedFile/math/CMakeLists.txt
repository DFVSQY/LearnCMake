add_executable(MakeTable src/make_table.cpp)

# Add a custom build rule to the generated build system.
add_custom_command(

	# Specify the output files the command is expected to produce
	# 生成一个名叫 ${CMAKE_CURRENT_BINARY_DIR}/Table.h 的“文件”（该文件不可见），
	# 其代表下方的 COMMAND 命令
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h

	# 具体要执行的自定义命令
	COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h

	# 需要依赖可执行目标MakeTable
	# 确保执行自定义命令前该Target先被执行
	DEPENDS MakeTable
)

# we have to let CMake know that 'my_math.cpp' depends on the generated file Table.h.
# This is done by adding the generated Table.h to the list of sources for the library 'mymath'.
# 添加了${CMAKE_CURRENT_BINARY_DIR}/Table.h才能触发自定义命令的执行
add_library(mymath src/my_math.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

target_include_directories(mymath PUBLIC includes PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_compile_definitions(mymath PRIVATE MYMATH_EXPORTS)