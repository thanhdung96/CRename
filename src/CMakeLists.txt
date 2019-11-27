cmake_minimum_required(VERSION 3.0)

project(crename)

file(GLOB CRename_SRC
    "*.h"
    "*.cpp"
)

include_directories("~/Documents/CPP/libs")
add_definitions(-DIS_LINUX)

add_executable(crename ${CRename_SRC})

install(TARGETS crename RUNTIME DESTINATION bin)
