cmake_minimum_required(VERSION 3.10)
project(fastcgi2-logger)

#set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_library(fastcgi2-logger SHARED
        logger.cpp
        logger.h)

target_link_libraries(fastcgi2-logger fastcgi_daemon2_lib)

#set_target_properties(fastcgi2-logger PROPERTIES LINK_FLAGS "-lpthread -ldl -lfcgi -lfcgi++ -llog4cxx")