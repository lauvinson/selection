cmake_minimum_required(VERSION 3.17)
project(selection C)

set(CMAKE_C_STANDARD 11)
#link_libraries(ws2_32 wsock32)

#add_executable(selection main.c stdlist.h stdlist.c map.h map.c server.c test.c server.h server_udp.c)
add_executable(selection main.c server.h server_udp_linux.c)