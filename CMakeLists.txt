cmake_minimum_required(VERSION 3.16)
project(ray-tracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_SFML "Enable SFML GUI preview" ON)

set(SOURCES
    src/main.cpp
    src/ray.cpp
    src/sphere.cpp
    src/hittable_list.cpp
    src/material.cpp
    src/util.cpp
)

add_executable(ray-tracer ${SOURCES})

if(USE_SFML)
    find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)
    target_link_libraries(ray-tracer PRIVATE sfml-graphics sfml-window sfml-system)
    target_compile_definitions(ray-tracer PRIVATE USE_SFML)
endif()
