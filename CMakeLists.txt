cmake_minimum_required(VERSION 3.14)
project(space-simulator LANGUAGES CXX)

# Use C++23 and disable compiler extensions for portability
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Provide conservative defaults for single-config generators
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

# Platform/compiler-specific warning flags
if(MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# --- Subprojects ---
add_subdirectory(src/graphics)
add_subdirectory(src/input)
add_subdirectory(src/simulation)
add_subdirectory(src/physics)

# --- Main app ---
add_executable(SpaceSimulator src/main.cpp)

target_link_libraries(SpaceSimulator PRIVATE
    graphics
    input
    physics
    simulation
)

# If the executable needs the top-level include folder, prefer relying on
# libraries to provide their include directories. Keep it here only if
# main.cpp depends on headers in include/ root.
target_include_directories(SpaceSimulator PRIVATE ${PROJECT_SOURCE_DIR}/include)

# --- GoogleTest setup (fetched once globally) ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # prevent CRT conflicts

# Make gtest available only when running tests
# This will populate the googletest targets so tests can link against them.
FetchContent_MakeAvailable(googletest)

# --- Enable CTest framework ---
enable_testing()

# --- Add tests ---
add_subdirectory(tests)
