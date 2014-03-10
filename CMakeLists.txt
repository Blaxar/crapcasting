cmake_minimum_required(VERSION 2.8)
project(CrapCasting)

# CMake vars override
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules")

find_package( OpenCV REQUIRED )

set(DEFAULT_SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(DEFAULT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(DEFAULT_LINK_DIR ${CMAKE_SOURCE_DIR}/libs)
set(DEFAULT_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/bin)

include_directories(${DEFAULT_INCLUDE_DIR} ${OpenCV_INCLUDE_DIR})
link_directories(${DEFAULT_LINK_DIR} ${OpenCV_LIBS})

add_subdirectory(${DEFAULT_SRC_DIR})
