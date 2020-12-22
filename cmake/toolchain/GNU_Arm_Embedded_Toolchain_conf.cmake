###############################################################################
# Check for env variable where compiler is placed 
if(DEFINED ENV{ARM_GCC_COMPILER_DIR})
	set(COMP_ENV_PATH $ENV{ARM_GCC_COMPILER_DIR} CACHE INTERNAL "ARM_GCC_COMPILER_DIR path")
	# Replace backslashes to slashes
	string(REPLACE "\\" "/" COMP_ENV_PATH ${COMP_ENV_PATH})
	set(COMP_ENV_PATH "${COMP_ENV_PATH}")
endif()
###############################################################################
# Set compiler extension. Depends on current host system.
if(WIN32)
	set(COMPILER_EXE_EXTENSION ".exe")
elseif(UNIX)
	set(COMPILER_EXE_EXTENSION "")
endif()
###############################################################################
set(TARGET_TRIPLET "arm-none-eabi" CACHE INTERNAL "ARM GCC Toolchain target triplet")

set(COMPILER_BIN "${COMP_ENV_PATH}/bin/" CACHE INTERNAL "GCC Compiler Path")
###############################################################################
