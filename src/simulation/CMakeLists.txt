add_library(simulation STATIC
    SpaceObject.cpp
    SimulationEngine.cpp
)

target_include_directories(simulation PUBLIC
    ${CMAKE_SOURCE_DIR}/include/simulation
)