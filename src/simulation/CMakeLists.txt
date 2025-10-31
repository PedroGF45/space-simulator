add_library(simulation STATIC
    SpaceObject.cpp
    SimulationEngine.cpp
)

# Expose top-level include directory so consumers include <simulation/...>
target_include_directories(simulation PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(simulation PRIVATE 
    SpaceObject.cpp 
    SimulationEngine.cpp
)

target_compile_features(simulation PUBLIC cxx_std_23)