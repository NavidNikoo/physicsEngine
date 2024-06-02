cmake_minimum_required(VERSION 3.28.1)
project(physicsEngine)
set(CMAKE_CXX_STANDARD 17)

# Define the Math library
add_library(Math
        src/Math/Math.cpp
        src/Math/Mat.h
        src/Math/Quat.h
        src/Math/Shape.h
        src/Math/Vec.h
)

target_include_directories(Math PUBLIC
        "${PROJECT_SOURCE_DIR}/src/Math"
)

# Set Vulkan SDK paths
set(VULKAN_SDK "${PROJECT_SOURCE_DIR}/Dependencies/Vulkan")

# Include Vulkan headers
include_directories(${VULKAN_SDK}/include)

# Link Vulkan libraries
link_directories(${VULKAN_SDK}/lib)

# Find Vulkan package
find_package(Vulkan REQUIRED)

# Set GLFW paths
set(GLFW_PATH "${PROJECT_SOURCE_DIR}/Dependencies/GLFW")

# Include GLFW headers
include_directories(${GLFW_PATH}/include)

# Link GLFW libraries
link_directories(${GLFW_PATH}/lib)

# Add GLM include directory
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/glm/include")

# Define the executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link the Math library, Vulkan, and GLFW to the physicsEngine executable
# Explicitly specify the full path to the GLFW library
target_link_libraries(physicsEngine PUBLIC Math Vulkan::Vulkan "${GLFW_PATH}/lib/libglfw.3.dylib")

# Specify the library directories for Vulkan and GLFW
target_link_directories(physicsEngine PUBLIC
        "${VULKAN_SDK}/lib"
        "${GLFW_PATH}/lib"
)
