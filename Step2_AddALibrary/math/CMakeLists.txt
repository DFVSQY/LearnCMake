# Adds a library target called <name> to be built from the source files listed in the command invocation
# STATIC, SHARED, or MODULE may be given to specify the type of library to be created. 
# STATIC libraries are archives of object files for use when linking other targets. 
# SHARED libraries are linked dynamically and loaded at runtime. 
# MODULE libraries are plugins that are not linked into other targets 
# but may be loaded dynamically at runtime using dlopen-like functionality. 
# If no type is given explicitly the type is STATIC or SHARED based on 
# whether the current value of the variable BUILD_SHARED_LIBS is ON.
add_library(mymath src/my_math.c)

target_include_directories(mymath PUBLIC includes)

# Specifies compile definitions to use when compiling a given <target>. 
# The named <target> must have been created by a command such as add_executable() or add_library() 
# and must not be an ALIAS target.
# MSVC工具链才需要这个宏定义
target_compile_definitions(mymath PUBLIC MYMATH_EXPORTS)