###############################################################################
# Common compiler options
add_compile_options(-fdata-sections)
add_compile_options(-ffunction-sections)
# Reproducibility option
add_compile_options(-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.)
###############################################################################
# Common warnings
add_compile_options(-Wall)
add_compile_options(-Wfatal-errors)
###############################################################################
# C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
###############################################################################
# CXX standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
###############################################################################
