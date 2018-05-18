cmake_minimum_required(VERSION 3.9)
project(TravelingSalesmanCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(TravelingSalesmanCpp
        headers/Point.h
        src/main.cpp
        src/Point.cpp src/HamiltonianPath.cpp headers/HamiltonianPath.h src/City.cpp headers/City.h src/CitySeed.cpp headers/CitySeed.h src/Drawer.cpp headers/Drawer.h)

target_link_libraries(TravelingSalesmanCpp GL)
target_link_libraries(TravelingSalesmanCpp glut)
