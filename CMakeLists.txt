## FY'S CMAKE LIST ##

cmake_minimum_required(VERSION 3.21...3.27)

# project name, description, and language
project(fy
    DESCRIPTION "Application to fight financial insecurity"
    LANGUAGES CXX)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# add src code
add_executable(fy src/main.cpp)

# private vs. public lib & cxx std - will use cxx 17
target_compile_features(fy PRIVATE cxx_std_17)

# dir for include header
target_include_directories(fy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

# list sources
target_sources(fy PUBLIC src/main.cpp
    # liboai core
    dep/liboai/liboai/core/authorization.cpp
    dep/liboai/liboai/core/netimpl.cpp
    dep/liboai/liboai/core/response.cpp
    # liboai modules
    dep/liboai/liboai/components/chat.cpp
    )

# liboai dep and linking
target_include_directories(fy PRIVATE
    "${CMAKE_SOURCE_DIR}/dep/liboai/liboai/include")
target_include_directories(fy PRIVATE
    "${CMAKE_SOURCE_DIR}/dep/liboai/liboai/include/components")
target_include_directories(fy PRIVATE
    "${CMAKE_SOURCE_DIR}/dep/liboai/liboai/include/core")

# link lib needed
target_link_libraries(fy PUBLIC
    openal
    curl
    )

# Typically you don't care so much for a third party library's tests to be
# run from your own project's code.
set(JSON_BuildTests OFF CACHE INTERNAL "")

# If you only include this third party in PRIVATE source files, you do not
# need to install it when your main project gets installed.
# set(JSON_Install OFF CACHE INTERNAL "")

# Don't use include(nlohmann_json/CMakeLists.txt) since that carries with it
# unintended consequences that will break the build.  It's generally
# discouraged (although not necessarily well documented as such) to use
# include(...) for pulling in other CMake projects anyways.
add_subdirectory("${CMAKE_SOURCE_DIR}/dep/json")

target_link_libraries(fy PRIVATE nlohmann_json::nlohmann_json)

# see include/.h dir
target_include_directories(fy PUBLIC ${CMAKE_SOURCE_DIR}/include)

# debug compile flags
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")

add_custom_command(TARGET fy PRE_BUILD
  COMMAND
    ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/env.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/.env  # dotenv
    env
)

set(ENV{OPENAI_API_KEY} "$ENV{OPENAI_API_KEY}")

IF (DEFINED ENV{OPENAI_API_KEY})
    MESSAGE(STATUS "env seen $ENV{OPENAI_API_KEY}")
ELSE()
    MESSAGE(STATUS "WTF")
ENDIF()