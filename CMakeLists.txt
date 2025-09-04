cmake_minimum_required(VERSION 3.10)

project(SpaceSimulator CXX)

add_subdirectory(src/graphics)
add_subdirectory(src/input)
add_subdirectory(src/physics)
add_subdirectory(src/simulation)

add_executable(SpaceSimulator src/main.cpp "include/simulation/Vector3D.h")

target_link_libraries(SpaceSimulator PUBLIC
    graphics
    input
    physics
    simulation
)