###############################################################################
# Setup Linker options
###############################################################################
add_link_options(-Wl,--gc-sections)
add_link_options(--specs=nano.specs)
add_link_options(--specs=nosys.specs)
add_link_options(-Wl,--print-memory-usage)
add_link_options(-T${CMAKE_CURRENT_SOURCE_DIR}/STM32F407VGTx_FLASH.ld)
add_link_options(-Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.map)
###############################################################################
