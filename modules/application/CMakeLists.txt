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
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/stm32f4xx_it.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(${PROJECT_NAME} PRIVATE FreeRTOS)
target_link_libraries(${PROJECT_NAME} PRIVATE Segger_RTT)
target_link_libraries(${PROJECT_NAME} PRIVATE CMSIS_STM32F4xx_GCC)
target_link_libraries(${PROJECT_NAME} PRIVATE STM32F4xx_LL_Driver)
target_link_libraries(${PROJECT_NAME} PRIVATE STM32F4xx_HAL_Driver)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} ARGS -Oihex $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.hex
    DEPENDS ${PROJECT_NAME}
)

add_custom_target(${PROJECT_NAME}_hex ALL DEPENDS ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.hex)
###############################################################################
