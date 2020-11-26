cmake_minimum_required(VERSION 3.17)
project(selection C)

set(CMAKE_C_STANDARD 11)
#link_libraries(ws2_32 wsock32)

#add_executable(selectifon main.c stdlist.h stdlist.c map.h map.c server.c test.c server.h server_udp.c)
add_executable(${PROJECT_NAME} server.h server_linux.c server_udp_linux.c)

find_package(Threads)
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})