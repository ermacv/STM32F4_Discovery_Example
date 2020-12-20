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
project(STM32F4xx_HAL_Driver)
###############################################################################
set(LIB_HAL_SRC
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_adc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_adc_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_can.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_cec.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_cortex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_crc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_cryp.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_cryp_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dac.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dac_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dcmi.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dcmi_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dfsdm.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dma.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dma2d.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dma_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_dsi.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_eth.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_exti.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_flash.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_flash_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_flash_ramfunc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_fmpi2c.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_fmpi2c_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_fmpsmbus.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_gpio.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_hash.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_hash_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_hcd.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_i2c.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_i2c_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_i2s.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_i2s_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_irda.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_iwdg.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_lptim.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_ltdc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_ltdc_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_mmc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_msp_template.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_nand.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_nor.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_pccard.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_pcd.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_pcd_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_pwr.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_pwr_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_qspi.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_rcc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_rcc_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_rng.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_rtc.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_rtc_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_sai.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_sai_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_sd.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_sdram.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_smartcard.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_smbus.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_spdifrx.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_spi.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_sram.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_tim.c
    # ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_timebase_rtc_alarm_template.c
    # ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_timebase_rtc_wakeup_template.c
    # ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_timebase_tim_template.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_tim_ex.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_uart.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_usart.c
    ${PROJECT_SOURCE_DIR}/Src/stm32f4xx_hal_wwdg.c
)

add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE ${LIB_HAL_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/Inc)
target_link_libraries(${PROJECT_NAME} PRIVATE CMSIS_STM32F4xx_GCC)
target_link_libraries(${PROJECT_NAME} PUBLIC HAL_Config)
target_compile_definitions(${PROJECT_NAME} PRIVATE USE_FULL_LL_DRIVER)
###############################################################################
