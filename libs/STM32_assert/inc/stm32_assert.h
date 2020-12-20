#ifndef STM32_ASSERT_H
#define STM32_ASSERT_H

#include "app_assert.h"
#define assert_param(expr) if ((expr) == 0) {app_assert(__func__, __FILE__, __LINE__); for( ;; );}

#endif // STM32_ASSERT_H