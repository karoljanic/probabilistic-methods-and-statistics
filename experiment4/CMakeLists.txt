cmake_minimum_required(VERSION 3.12)

project (random-walk-with-coverage)

file(GLOB src
    "*.hpp"
    "*.cpp")

add_executable(main ${src})
