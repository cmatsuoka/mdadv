cmake_minimum_required(VERSION 3.1)

project(mdadv)

include_directories(advsys)

set(CMAKE_BUILD_TYPE Debug)

find_package(SDL REQUIRED)

add_subdirectory(advsys)
add_subdirectory(calixto)

