add_library(simulation STATIC
    SpaceObject.cpp
    SimulationEngine.cpp
)

target_include_directories(simulation PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(simulation PRIVATE SpaceObject.cpp SimulationEngine.cpp)

target_compile_features(simulation PUBLIC cxx_std_23)