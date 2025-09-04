add_library(input STATIC
    InputManager.cpp
)

target_include_directories(input PUBLIC
    ${CMAKE_SOURCE_DIR}/include/input
)