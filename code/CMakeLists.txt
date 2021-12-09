# cmake版本需求
CMAKE_MINIMUM_REQUIRED(VERSION 3.2.0)

# 工程名称
PROJECT(PROJECT_CC)

ADD_SUBDIRECTORY(comm)

include(
    ${CMAKE_CURRENT_SOURCE_DIR}/../cmake_conf/building_output.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/../cmake_conf/compiler_conf.cmake
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/comm/include)

add_executable(PROJECT_CC)

target_sources(PROJECT_CC
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(PROJECT_CC
PRIVATE
    comm
)

