cmake_minimum_required(VERSION 3.15)

project(AddALibray VERSION 1.0)

# 将库编译成动态库
set(BUILD_SHARED_LIBS ON)

# 主要是为了将输出的exe和dll放到同一个目录，
# 这样exe才能正常运行起来，否则dll不在exe的动态库搜索目录中
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Provide a boolean option that the user can optionally select
option(USE_MYMATH "whether to use my math lib" ON)

configure_file(inc/AddALibrary.h.in includes/AddALibrary.h)

# Adds a subdirectory to the build
# When MY_MATH is ON, the lists will be generated and will be added to our project.
# When MY_MATH is OFF, the lists stay empty.
# With this strategy, we allow users to toggle MY_MATH to manipulate what library is used in the build.
if(USE_MYMATH)
	add_subdirectory(math)

	# list(APPEND <list> [<element> ...])
	# Appends elements to the list.
	# If no variable named <list> exists in the current scope its value is treated as empty
	# and the elements are appended to that empty list.
	list(APPEND EXTRA_LIBS mymath)
	list(APPEND EXTRA_INCLUDES math/includes)
endif()

add_subdirectory(main)
