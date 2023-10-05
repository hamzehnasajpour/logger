cmake_minimum_required(VERSION 3.10)
project(logger)
add_library(logger Syslog.cpp)
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


option(BUILD_EXAMPLE "BUILD_EXAMPLE" FALSE)
if(BUILD_EXAMPLE)
    message(STATUS "Example will be built.")
    add_executable(example ./example/example.cpp)
    target_link_libraries(example logger)
endif()