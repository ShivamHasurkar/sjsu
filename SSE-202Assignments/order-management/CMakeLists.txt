cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(OrderManagementSystem VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(OrderManagementSystem main.cpp)

# Include directories
target_include_directories(OrderManagementSystem PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/models"
                           "${PROJECT_SOURCE_DIR}/controllers"
                           "${PROJECT_SOURCE_DIR}/facade"
                           "${PROJECT_SOURCE_DIR}/views")
