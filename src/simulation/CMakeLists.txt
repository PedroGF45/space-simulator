add_library(simulation STATIC
    Engine.cpp
)

target_include_directories(simulation PUBLIC
    ${CMAKE_SOURCE_DIR}/include/simulation
)