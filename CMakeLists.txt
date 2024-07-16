# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SolEngine VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include/core)
include_directories(${PROJECT_SOURCE_DIR}/include/stb)
include_directories(${PROJECT_SOURCE_DIR}/include/rapidxml)

# Add the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define the executable
add_executable(program ${SOURCES} src/main.cpp)

# Find and link GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(program PRIVATE glfw)

# Find and link GLEW
find_package(GLEW REQUIRED)
target_link_libraries(program PRIVATE GLEW::GLEW)

# Find and link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(program PRIVATE OpenGL::GL)

# Specify the build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Optionally, you might want to specify some compiler flags
target_compile_options(program PRIVATE
    -Wall
    -Wextra
    -ggdb
)

# To handle creation of directories for build files (this is automatic in CMake, but it can be explicitly set if needed)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/obj)

# Custom target to clean build files
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/clean.cmake
    COMMENT "Cleaning all build files"
)

# Create a clean.cmake file to handle custom clean logic
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/clean.cmake
    "file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/obj)\n"
    "file(REMOVE ${CMAKE_BINARY_DIR}/program)\n"
)

# Ensure the custom clean target is executed with `clean` and `rebuild`
add_custom_target(rebuild
    COMMAND ${CMAKE_BUILD_TOOL} clean_all
    COMMAND ${CMAKE_BUILD_TOOL}
    COMMENT "Rebuilding the project"
)

# Mark custom targets as not part of the default build
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_BINARY_DIR}/clean.cmake)
