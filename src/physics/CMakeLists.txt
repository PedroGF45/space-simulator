add_library(physics STATIC
    GravitySystem.cpp
    VelocityVerlet.cpp
)

# Expose top-level include directory so consumers include <physics/...>
target_include_directories(physics PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(physics PRIVATE
    GravitySystem.cpp
    VelocityVerlet.cpp
)

target_compile_features(physics PUBLIC cxx_std_23)

# Physics depends on simulation types (SpaceObject)
target_link_libraries(physics PUBLIC simulation)