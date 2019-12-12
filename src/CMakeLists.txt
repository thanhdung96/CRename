cmake_minimum_required(VERSION 3.0)

project(crename)

file(GLOB CRename_SRC
    "*.h"
    "*.cpp"
)

SET(Boost_INCLUDE_DIRS "/home/thanhdung/Documents/CPP/libs/boost_1_71_0/out/include/")
SET(Boost_LIBRARIES "/home/thanhdung/Documents/CPP/libs/boost_1_71_0/out/lib/")
add_definitions(-DIS_LINUX)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.71.0 COMPONENTS filesystem)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(crename ${CRename_SRC}) 
    target_link_libraries(crename ${Boost_LIBRARIES})
endif()

