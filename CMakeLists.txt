## FY'S CMAKE LIST ##

cmake_minimum_required(VERSION 3.16...3.27)

# project name, description, and language
project(fy
    DESCRIPTION "Application to fight financial insecurity"
    LANGUAGES CXX)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

file(GLOB LIBOAI_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/components/*.cpp
    )

# add src code
add_executable(fy src/main.cpp
    ${LIBOAI_SRC}
    )

# private vs. public lib & cxx std - will use cxx 17
target_compile_features(fy PRIVATE cxx_std_17)

# dir for include header
target_include_directories(fy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(fy PUBLIC src/main.cpp)

# link lib needed
target_link_libraries(fy PUBLIC
    #${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai.a
    curl
    )

target_include_directories(fy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include/core
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include/components
    )

# debug compile flags
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
