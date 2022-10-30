add_executable(main src/main.c)

target_link_libraries(main PRIVATE mymath)

# 链接step_compile_flags
target_link_libraries(main PRIVATE step_compile_flags)
