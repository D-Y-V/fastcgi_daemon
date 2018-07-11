cmake_minimum_required(VERSION 3.10)
project(fastcgi2-filelogger)

#set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_library(fastcgi2-filelogger SHARED
        file_logger.cpp
        file_logger.h)

install(TARGETS fastcgi2-filelogger LIBRARY DESTINATION lib)