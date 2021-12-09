# CMakeLists for src directory
#PROJECT(comm)
#指定头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

cmake_minimum_required(VERSION 3.20)

#指定库文件
AUX_SOURCE_DIRECTORY(. COMM_SRCS)

# 编译动态库
add_library(comm SHARED)

target_sources(comm
PRIVATE
    ${COMM_SRCS}
)

target_include_directories(comm
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
