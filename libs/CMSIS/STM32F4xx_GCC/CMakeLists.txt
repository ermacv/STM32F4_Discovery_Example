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
project(CMSIS_STM32F4xx_GCC)
###############################################################################

add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Source/system_stm32f4xx.c)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Source/startup_stm32f407xx.s)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/Include)
target_compile_definitions(${PROJECT_NAME} PUBLIC STM32F407xx)
target_link_libraries(${PROJECT_NAME} PUBLIC CMSIS_Core)
###############################################################################
