cmake_minimum_required(VERSION 3.16)
project(ray-tracer)

file(GLOB SOURCES "src/*.cpp")
add_executable(ray-tracer ${SOURCES})
