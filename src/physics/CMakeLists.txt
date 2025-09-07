add_library(physics STATIC
    GravitySystem.cpp
)

target_include_directories(physics PUBLIC
    ${CMAKE_SOURCE_DIR}/include/physics
)

target_link_libraries(physics PUBLIC simulation)