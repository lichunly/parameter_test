cmake_minimum_required(VERSION 2.8)
project(parameter_test)

set(CMAKE_C_COMPILER /usr/bin/gcc CACHE PATH "")
set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE PATH "")

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread")
set(CMAKE_BUILD_TYPE Release)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O0 -Wall -g -ggdb")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native -O0 -Wall -g -ggdb")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O2")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native -O2")
endif ()

add_definitions(-DMODULE_NAME="parameter_test")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

include(${CMAKE_SOURCE_DIR}/cmake/Gears.cmake)

# Common
include(${CMAKE_SOURCE_DIR}/cmake/Common.cmake)

# GLog
include(${CMAKE_SOURCE_DIR}/cmake/GLog.cmake)

# GTest
include(${CMAKE_SOURCE_DIR}/cmake/GTest.cmake)

#Grpc
include(${CMAKE_SOURCE_DIR}/cmake/Grpc.cmake)

# Protobuf
set(PROTOBUF_ROOT "${GEARS_ARCH}" CACHE INTERNAL "PROTOBUF_ROOT")
include(${CMAKE_SOURCE_DIR}/cmake/Protobuf.cmake)

# Boost
include(${CMAKE_SOURCE_DIR}/cmake/Boost.cmake)

# Cyber
include(${CMAKE_SOURCE_DIR}/cmake/Cyber.cmake)

include_directories(
        ${CMAKE_SOURCE_DIR}/src
)

add_subdirectory(src)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/launch/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/launch)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dag/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/dag)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/conf/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/conf)
