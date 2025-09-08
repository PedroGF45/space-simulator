add_library(physics STATIC
    GravitySystem.cpp
)

# Physics may include headers from the main include tree
target_include_directories(physics PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(physics PRIVATE GravitySystem.cpp)

target_compile_features(physics PUBLIC cxx_std_23)

# If physics' public headers include simulation headers, keep PUBLIC;
# otherwise prefer PRIVATE. Adjusted to PUBLIC because original used PUBLIC.
target_link_libraries(physics PUBLIC simulation)