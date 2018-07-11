cmake_minimum_required(VERSION 3.10)
project(fastcgi_daemon2)

#set(CMAKE_CXX_STANDARD 11)

add_library(fastcgi_daemon2 SHARED
        component.cpp
        component_context.cpp
        component_factory.cpp
        componentset.cpp
        config.cpp
        cookie.cpp
        data_buffer.cpp
        except.cpp
        globals.cpp
        handler.cpp
        handlerset.cpp
        loader.cpp
        logger.cpp
        parser.cpp
        request.cpp
        request_filter.cpp
        request_thread_pool.cpp
        requestimpl.cpp
        response_time_statistics.cpp
        server.cpp
        stream.cpp
        string_buffer.cpp
        util.cpp
        xml.cpp)

set_target_properties(fastcgi_daemon2 PROPERTIES LINK_FLAGS "-lpthread -ldl -lfcgi -lfcgi++")



file(
	GLOB
    fastcgi_daemon2_include_files
    "${CMAKE_CURRENT_SOURCE_DIR}/../include/fastcgi2/*.h"
)
set_target_properties(fastcgi_daemon2 PROPERTIES
	PUBLIC_HEADER "${fastcgi_daemon2_include_files}"
)


install(TARGETS fastcgi_daemon2 LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include/fastcgi2)