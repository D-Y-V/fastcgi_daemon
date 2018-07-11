cmake_minimum_required(VERSION 3.10)
project(fastcgi-daemon2)

#set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(fastcgi-daemon2
        endpoint.cpp
        endpoint.h
        fcgi_request.cpp
        fcgi_request.h
        fcgi_server.cpp
        fcgi_server.h
        main.cpp)

target_link_libraries(fastcgi-daemon2 fastcgi_daemon2)

set_target_properties(fastcgi-daemon2 PROPERTIES LINK_FLAGS "-lpthread -ldl -lfcgi -lfcgi++ -lxml2")

install(TARGETS fastcgi-daemon2 RUNTIME DESTINATION bin)