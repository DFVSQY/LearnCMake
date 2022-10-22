add_executable(main src/main.c)

target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR}/includes ${EXTRA_INCLUDES})

# Specify libraries or flags to use when linking a given target and/or its dependents.
# Usage requirements from linked library targets will be propagated.
# Usage requirements of a target's dependencies affect compilation of its own sources.
# The PUBLIC, PRIVATE and INTERFACE scope keywords can be used to specify both the link dependencies
# and the link interface in one command.
target_link_libraries(main PUBLIC ${EXTRA_LIBS})