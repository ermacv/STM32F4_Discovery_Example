#include "app_assert.h"

#include "SEGGER_RTT.h"

void app_assert(const char *func, const char *file, int line)
{
    SEGGER_RTT_printf(0, "Assert failed. Function: %s. File: %s at line %d\r\n", func, file, line);
}