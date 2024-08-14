cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE on)

add_compile_options(
        -fexceptions
        -frtti
        -std=c++17)
# 将当前目录下的cpp结尾的文件赋值给变量tm_SRC
file(GLOB tm_SRC CONFIGURE_DEPENDS *.cpp)
# 创建名为tm的静态链接库
add_library(tm STATIC ${tm_SRC})
# 将当前目录添加到头文件查找目录
target_include_directories(tm PUBLIC .)
# 将当前目录添加到头文件查找目录
target_include_directories(react_codegen_RTNBase64HelperSpec PUBLIC .)
# 为tm这个库设置需要链接的库
target_link_libraries(tm
        jsi
        react_nativemodule_core
        react_codegen_RTNBase64HelperSpec)