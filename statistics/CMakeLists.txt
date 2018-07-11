cmake_minimum_required(VERSION 3.10)
project(fastcgi2-statistics)

#set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_library(fastcgi2-statistics SHARED
        response_time_handler.cpp
        response_time_handler.h)

target_link_libraries(fastcgi2-statistics fastcgi_daemon2)

install(TARGETS fastcgi2-statistics LIBRARY DESTINATION lib)