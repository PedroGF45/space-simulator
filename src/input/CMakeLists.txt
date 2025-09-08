add_library(input STATIC
    InputManager.cpp
)

target_include_directories(input PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(input PRIVATE InputManager.cpp)

target_compile_features(input PUBLIC cxx_std_23)