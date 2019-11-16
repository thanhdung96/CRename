cmake_minimum_required(VERSION 3.0)

project(crename)

add_executable(crename main.cpp)

install(TARGETS crename RUNTIME DESTINATION bin)
