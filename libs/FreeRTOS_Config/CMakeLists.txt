###############################################################################
# Minimal CMake version that is needed to process current project
cmake_minimum_required(VERSION 3.6)
###############################################################################
###############################################################################
# Languages that are used in the project
enable_language(ASM)
enable_language(C)
###############################################################################
# Main project name
project(FreeRTOS_Config)
###############################################################################
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} INTERFACE app_assert)
###############################################################################
