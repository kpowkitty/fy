## FY'S CMAKE LIST ##

cmake_minimum_required(VERSION 3.16...3.27)

# project name, description, and language
project(fy
    DESCRIPTION "Application to fight financial insecurity"
    LANGUAGES CXX)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# add src code
add_executable(fy src/main.cpp)

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

# !have not tested doc yet, look into
option(BUILD_DOC "Build documentation" ON)
# check if doxygen is installed
find_package(Doxygen REQUIRED)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    # request to configure the files
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message(STATUS "Doxygen build started")
    # NOTE: ALL builds doc together with app - all targets
    add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY $CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else (DOXYGEN_FOUND)
    message(STATUS "Doxygen needs to be installed to generate doxygen
    documentation")
endif (DOXYGEN_FOUND)
