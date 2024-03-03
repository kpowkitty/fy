## FY'S CMAKE LIST ##

cmake_minimum_required(VERSION 3.16...3.27)

# project name, description, and language
project(fy
    DESCRIPTION "Application to fight financial insecurity"
    LANGUAGES CXX)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# glob liboai src
file(GLOB LIBOAI_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/components/*.cpp
    )

# add src code
add_executable(fy src/ai.cpp
    )

# link sfml static lib
# set(SFML_STATIC_LIBRARIES TRUE)
if(TARGET_SYSTEM_LINUX)
    target_include_directories(fy PRIVATE
        "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/include/")
    target_link_directories(fy PRIVATE
        "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/lib/")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/lib/cmake/SFML")
elseif(TARGET_SYSTEM_WIN32)
    target_include_directories(fy PRIVATE
        "${CMAKE_SOURCE_DIR}/dep/SFML-2.6.1/include/")
    target_link_directories(fy PRIVATE
        "${CMAKE_SOURCE_DIR}/dep/SFML-2.6.1/lib/")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/dep/SFML-2.6.1/lib/cmake/SFML")
endif()

if(TARGET_SYSTEM_LINUX)
    target_include_directories(test PRIVATE
        "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/include/")
    target_link_directories(test PRIVATE
        "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/lib/")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/lib/cmake/SFML")
elseif(TARGET_SYSTEM_WIN32)
    target_include_directories(test PRIVATE
        "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/include/")
    target_link_directories(test PRIVATE
        "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/lib/")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/dep/linux/SFML-2.6.1/lib/cmake/SFML")
endif()

find_package(SFML COMPONENTS network graphics window system REQUIRED)

# private vs. public lib & cxx std - will use cxx 17
target_compile_features(fy PRIVATE cxx_std_17)

# dir for include header
target_include_directories(fy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/libaoi/liboai/include)

# dir for lib to link
target_link_directories(fy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/perl/)

target_sources(fy PUBLIC src/ai.cpp)

# link lib needed
target_link_libraries(fy PUBLIC
    #${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai.a
    curl
    sfml-graphics
    sfml-window
    sfml-system
    OpenGL
    GL
    liboai.a
    )

# include local include, liboai include, and json include
target_include_directories(fy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include/core/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include/components/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/json/single_include/
    #${CMAKE_CURRENT_SOURCE_DIR}/dep/curl/include/
    )

# debug compile flags
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")


## TESTING EXECUTABLE ##

add_executable(test src/test.cpp
    ${LIBOAI_SRC}
    )

#private vs. public lib & cxx std - will use cxx 17
target_compile_features(test PRIVATE cxx_std_17)

# dir for include header
target_include_directories(test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/libaoi/liboai/include)


target_sources(test PUBLIC src/test.cpp
    src/ai.cpp)

# link lib needed
target_link_libraries(test PUBLIC
    #${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai.a
    curl
    sfml-graphics
    sfml-system
    OpenGL
    GL
    )

# include local include, liboai include, and json include
target_include_directories(test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include/core/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/liboai/liboai/include/components/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/json/single_include/
    ${CMAKE_CURRENT_SOURCE_DIR}/dep/curl/include/
    )

