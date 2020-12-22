#include <stddef.h>

#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_bus.h"

#include "FreeRTOS.h"
#include "task.h"

#include "SEGGER_RTT.h"

#include "stm32f4xx_hal.h"

/****************************************************************************/
static void SystemClock_Config(void);
/****************************************************************************/
/****************************************************************************/

static void vTaskCode(void *param)
{
  SEGGER_RTT_printf(0, "Thread: %s started\r\n", __func__);
  size_t counter = 0;
  while (1)
  {
    TaskStatus_t pxTaskStatus;
    vTaskGetInfo(NULL, &pxTaskStatus, pdTRUE, eInvalid);
    // uxHighWaterMark = uxTaskGetStackHighWaterMark(cipTask);
    SEGGER_RTT_printf(0, "counter: %d\r\n", counter++);
    // SEGGER_RTT_printf(0, "uxHighWaterMark: %d\r\n", pxTaskStatus.eCurrentState);
    SEGGER_RTT_printf(0, "pcTaskName: %s\r\n", pxTaskStatus.pcTaskName);
    SEGGER_RTT_printf(0, "usStackHighWaterMark: %d\r\n", pxTaskStatus.usStackHighWaterMark);
    SEGGER_RTT_printf(0, "xTaskNumber: %d\r\n", pxTaskStatus.xTaskNumber);
    // SEGGER_RTT_printf(0, "uxHighWaterMark: %d\r\n", pxTaskStatus.eCurrentState);
    // SEGGER_RTT_printf(0, "uxHighWaterMark: %d\r\n", pxTaskStatus.eCurrentState);
    vTaskDelay(1000);
  }
}

int main(void)
{
  SystemClock_Config();
  NVIC_SetPriorityGrouping(0);

  SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);
  SEGGER_RTT_WriteString(0, "Main started\r\n");

  TaskHandle_t xHandle = NULL;
  xTaskCreate(vTaskCode, "Test_thread", 128, NULL, 1, &xHandle);      /* Used to pass out the created task's handle. */
  vTaskStartScheduler();

  while(1)
  {

  }

  return 0;
}

static void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_5);
  while (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_5)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  LL_RCC_HSE_Enable();

  /* Wait till HSE is ready */
  while (LL_RCC_HSE_IsReady() != 1)
  {
  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_4, 168, LL_RCC_PLLP_DIV_2);
  LL_RCC_PLL_Enable();

  /* Wait till PLL is ready */
  while (LL_RCC_PLL_IsReady() != 1)
  {
  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_4);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

  /* Wait till System clock is ready */
  while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  }
  LL_SetSystemCoreClock(168000000);
}
