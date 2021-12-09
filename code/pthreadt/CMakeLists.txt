# CMakeLists for src directory
#PROJECT(pthreadt)
#指定头文件路径
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../rre
)

cmake_minimum_required(VERSION 3.20)

#指定库文件
AUX_SOURCE_DIRECTORY(. PTHREAD_SRCS)

# 编译动态库
add_library(pthreadt SHARED)

target_sources(pthreadt
PRIVATE
    ${PTHREAD_SRCS}
)

set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread")

target_include_directories(pthreadt
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../rre
)


