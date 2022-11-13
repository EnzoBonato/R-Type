cmake_minimum_required(VERSION 3.5)
SET(CMAKE_BUILD_TYPE)
project(R-Type)

# CHECK BOOST AND SFML WITH CONAN
include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# LINUX
if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -W -Wall -Wextra -ggdb -pthread")
  endif(UNIX)

# WINDOWS
if (MSVC)
find_program(conan_path conan)
execute_process(COMMAND ${conan_path} "install" "${PROJECT_SOURCE_DIR}" "-s" "compiler=Visual Studio" WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif(MSVC)

# CALL SUBDIRECTORY TO COMPILE
add_subdirectory(CLIENT)
add_subdirectory(SERVER)