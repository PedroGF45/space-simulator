add_library(graphics STATIC
    Renderer.cpp
)

target_include_directories(graphics PUBLIC
    ${CMAKE_SOURCE_DIR}/include/graphics
)