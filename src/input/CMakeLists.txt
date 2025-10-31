add_library(input STATIC
    InputManager.cpp
)

# Expose top-level include directory so consumers include <input/...>
target_include_directories(input PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(input PRIVATE InputManager.cpp)

target_compile_features(input PUBLIC cxx_std_23)