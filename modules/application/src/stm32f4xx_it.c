#include "SEGGER_RTT.h"

void NMI_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);
}

void HardFault_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

void MemManage_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

void BusFault_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

void UsageFault_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

void FLASH_IRQHandler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

void DebugMon_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

void FPU_IRQHandler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

__attribute__(( weak )) void SVC_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

__attribute__(( weak )) void PendSV_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}

__attribute__(( weak )) void SysTick_Handler(void)
{
  SEGGER_RTT_printf(0, "%s\r\n", __func__);

  while (1)
  {

  }
}
