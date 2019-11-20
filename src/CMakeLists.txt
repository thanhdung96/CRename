cmake_minimum_required(VERSION 3.0)

project(crename)

file(GLOB CRename_SRC
    "*.h"
    "*.cpp"
)

add_executable(crename ${CRename_SRC})

install(TARGETS crename RUNTIME DESTINATION bin)
