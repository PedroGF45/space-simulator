add_library(graphics STATIC
    Renderer.cpp
)

# Prefer exposing the top-level include directory so consumers can include
# <graphics/...>. Use generator expressions to separate build vs install.
target_include_directories(graphics PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Sources are implementation details
target_sources(graphics PRIVATE Renderer.cpp)

# Ensure target uses the required C++ standard
target_compile_features(graphics PUBLIC cxx_std_23)