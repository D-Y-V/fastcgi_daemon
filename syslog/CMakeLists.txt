cmake_minimum_required(VERSION 3.10)
project(fastcgi2-syslog)

#set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_library(fastcgi2-syslog SHARED
        syslog-logger.cpp
        syslog-logger.h)

target_link_libraries(fastcgi2-syslog fastcgi_daemon2)

install(TARGETS fastcgi2-syslog LIBRARY DESTINATION lib)