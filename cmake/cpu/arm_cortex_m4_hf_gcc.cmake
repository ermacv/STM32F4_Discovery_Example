###############################################################################
# ARM Cortex-M4 and hard float point ABI options for GCC compiler
###############################################################################
# Check the link below to get a description for ARM specific options:
# https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html
###############################################################################
# By providing ISA, CPU architecture version, FPU HW version and FPU ABI type
# to the GCC it may include default C system libraries (newlib-nano) automatically
# by using milti-lib option (check arm-none-eabi-gcc --print-multi-lib)
###############################################################################
# Setup Compile options
add_compile_options(-march=armv7e-m)
add_compile_options(-mlittle-endian)
add_compile_options(-mcpu=cortex-m4)
add_compile_options(-mthumb)
add_compile_options(-mfpu=fpv4-sp-d16)
add_compile_options(-mfloat-abi=hard)
add_compile_options(-mapcs-frame)
###############################################################################
# Setup Linker options
###############################################################################
add_link_options(-march=armv7e-m)
add_link_options(-mlittle-endian)
add_link_options(-mcpu=cortex-m4)
add_link_options(-mthumb)
add_link_options(-mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard)
add_link_options(-mapcs-frame)
###############################################################################