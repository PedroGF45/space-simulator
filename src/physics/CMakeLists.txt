add_library(physics STATIC
    CelestialBody.cpp
)

target_include_directories(physics PUBLIC
    ${CMAKE_SOURCE_DIR}/include/physics
)