###############################################################################
# Common complier options
set(compiler_common_flags "")
set(compiler_common_flags "${compiler_common_flags} -fdata-sections")
set(compiler_common_flags "${compiler_common_flags} -ffunction-sections" CACHE INTERNAL "")
###############################################################################
# Common warnings
set(compiler_common_warnings "-Wall")
# set(compiler_common_warnings "${compiler_common_warnings} -pedantic")
set(compiler_common_warnings "${compiler_common_warnings} -Wfatal-errors" CACHE INTERNAL "")
###############################################################################
# C standard
set(PROJECT_C_STD "-std=c99" CACHE INTERNAL "")
###############################################################################
# CXX standard
set(PROJECT_CXX_STD "-std=c++14" CACHE INTERNAL "")
###############################################################################
# Setup C options
###############################################################################
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${PROJECT_C_STD}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${compiler_common_flags}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${compiler_common_warnings}")
###############################################################################
# Setup CXX options
###############################################################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PROJECT_CXX_STD}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${compiler_common_flags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${compiler_common_warnings}")
###############################################################################
# Setup ASM options
###############################################################################
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${compiler_common_flags}")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${compiler_common_warnings}")
###############################################################################
