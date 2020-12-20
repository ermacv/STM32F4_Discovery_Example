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
project(STM32F4xx_LL_Driver)
###############################################################################
set(LIB_LL_SRC
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_adc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_crc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_dac.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_dma.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_dma2d.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_exti.c
    # ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_fmc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_fmpi2c.c
    # ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_fsmc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_gpio.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_i2c.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_lptim.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_pwr.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_rcc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_rng.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_rtc.c
    # ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_sdmmc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_spi.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_tim.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_usart.c
    # ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_usb.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_utils.c
)

set(LIB_LL_HAL_SRC
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_fmc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_fsmc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_sdmmc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_ll_usb.c
)

add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE ${LIB_LL_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/Inc)
target_link_libraries(${PROJECT_NAME} PRIVATE CMSIS_STM32F4xx_GCC)
target_link_libraries(${PROJECT_NAME} PUBLIC stm32_assert)
target_compile_definitions(${PROJECT_NAME} PRIVATE USE_FULL_LL_DRIVER)
target_compile_definitions(${PROJECT_NAME} PRIVATE USE_FULL_ASSERT)

add_library(${PROJECT_NAME}_HAL STATIC)
target_sources(${PROJECT_NAME}_HAL PRIVATE ${LIB_LL_HAL_SRC})
target_include_directories(${PROJECT_NAME}_HAL PUBLIC ${PROJECT_SOURCE_DIR}/Inc)
target_link_libraries(${PROJECT_NAME}_HAL PRIVATE CMSIS_STM32F4xx_GCC)
target_link_libraries(${PROJECT_NAME}_HAL PRIVATE STM32F4xx_HAL_Driver)
target_link_libraries(${PROJECT_NAME}_HAL PUBLIC stm32_assert)
target_compile_definitions(${PROJECT_NAME}_HAL PRIVATE USE_FULL_LL_DRIVER)
target_compile_definitions(${PROJECT_NAME}_HAL PRIVATE USE_FULL_ASSERT)
###############################################################################
