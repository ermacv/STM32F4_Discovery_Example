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
project(application)
###############################################################################
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE CMSIS_STM32F4xx_GCC)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")
###############################################################################
