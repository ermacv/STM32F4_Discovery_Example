###############################################################################
# Minimal CMake version that is needed to process current project
cmake_minimum_required(VERSION 3.6)
###############################################################################
# CMake specific options that should be enabled before processing the project
# Must be enabled before project()
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/toolchain/GNU_Arm_Embedded_Toolchain.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
###############################################################################
# Languages that are used in the project
enable_language(C)
###############################################################################
# Main project name
project(STM32F4DISCO_Test)
###############################################################################
# Include CPU specific biuld options
include(${CMAKE_SOURCE_DIR}/cmake/cpu/arm_cortex_m4_hf_gcc.cmake)
# Include build options for different build types (Debug, Release, etc.)
include(${CMAKE_SOURCE_DIR}/cmake/build_common/build_types.cmake)
# Include common build options that should ne used by all project modules and libraries
include(${CMAKE_SOURCE_DIR}/cmake/build_common/build_options.cmake)
# Include chip linker options
include(${CMAKE_SOURCE_DIR}/cmake/chip/STM32F407_options.cmake)
###############################################################################
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/CMSIS/core)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/CMSIS/STM32F4xx_GCC)
add_subdirectory(${CMAKE_SOURCE_DIR}/modules/application)
# add_subdirectory(${CMAKE_SOURCE_DIR}/cmake/libs/stm32_ll)
# add_subdirectory(${CMAKE_SOURCE_DIR}/modules/system)
# add_subdirectory(${CMAKE_SOURCE_DIR}/modules/application)
# add_subdirectory(${CMAKE_SOURCE_DIR}/modules/led_control/pwm_timer)
# add_subdirectory(${CMAKE_SOURCE_DIR}/modules/led_control/counter_timer)
# add_subdirectory(${CMAKE_SOURCE_DIR}/modules/led_control/main)
# add_subdirectory(${CMAKE_SOURCE_DIR}/modules/button_control/main)
# add_subdirectory(${CMAKE_SOURCE_DIR}/modules/button_control/button_driver)
###############################################################################
