cmake_minimum_required(VERSION 3.10)
project(fastcgi_daemon)

#set(CMAKE_VERBOSE_MAKEFILE ON)
include(CheckLibraryExists)
include(CheckIncludeFileCXX)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
if(COMPILER_SUPPORTS_CXX17)
	message("Compiler ${CMAKE_CXX_COMPILER} has C++17 support.")
else()
    message(FATAL_ERROR "Compiler ${CMAKE_CXX_COMPILER} has NO C++17 support.")
endif()

# around libxml2
find_package(LibXml2 REQUIRED)
message(STATUS LIBXML2_INCLUDE_DIR = ${LIBXML2_INCLUDE_DIR})
include_directories(${LIBXML2_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")

include_directories(config) # one file
include_directories(include)

add_subdirectory(library)
add_subdirectory(main)
add_subdirectory(syslog)
add_subdirectory(statistics)
add_subdirectory(file-logger)



