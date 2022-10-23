add_executable(main src/main.c)

# 不需要指定该行命令，
# 因为math/CMakeLists.txt中的头文件目录已经被指定为PUBLIC了
# target_include_directories(main ../math/includes)

target_link_libraries(main PUBLIC mymath)