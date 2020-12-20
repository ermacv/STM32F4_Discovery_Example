###############################################################################
# Minimal CMake version that is needed to process current project
cmake_minimum_required(VERSION 3.6)
###############################################################################
# Languages that are used in the project
enable_language(ASM)
enable_language(C)
###############################################################################
# Main project name
project(app_assert)
###############################################################################
add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/app_assert.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(${PROJECT_NAME} PRIVATE Segger_RTT)
###############################################################################
