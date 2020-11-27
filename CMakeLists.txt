cmake_minimum_required(VERSION 3.17)
project(selection C)

set(CMAKE_C_STANDARD 11)
#link_libraries(ws2_32 wsock32)

if(WIN32 AND NOT MINGW)
    add_executable(selectifon main.c server.c test.c server.h server_udp.c)
elseif(WIN32 AND MINGW)
    message("MINGW 编译设置")
elseif(UNIX AND NOT ANDROID)
    add_executable(${PROJECT_NAME} main.c server.h server_linux.c server_udp_linux.c)
elseif(ANDROID)
    message("ANDROID 编译设置")
endif()

find_package(Threads)
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})