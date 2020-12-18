###############################################################################
# Minimal CMake version that is needed to process current project
cmake_minimum_required(VERSION 3.6)
###############################################################################
# Languages that are used in the project
enable_language(ASM)
enable_language(C)
###############################################################################
# Main project name
project(Segger_RTT)
###############################################################################
add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/SEGGER_RTT_V686/RTT/SEGGER_RTT.c)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/SEGGER_RTT_V686/RTT/SEGGER_RTT_printf.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/SEGGER_RTT_V686/RTT)
###############################################################################
