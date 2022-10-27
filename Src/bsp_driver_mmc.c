/*
 * bsp_driver_mmc.c
 *
 *  Created on: 10 июн. 2019 г.
 *      Author: Ярослав
 */
#include "bsp_driver_mmc.h"

extern MMC_HandleTypeDef hmmc;


uint8_t BSP_MMC_Init(void)
{
  uint8_t sd_state = MSD_OK;

  //sd_state = HAL_MMC_Init(&hmmc);

  return sd_state;
}

uint8_t BSP_MMC_ITConfig(void)
{


  return (uint8_t)0;
}


void BSP_MMC_DetectIT(void)
{

}


__weak void BSP_MMC_DetectCallback(void)
{

}


uint8_t BSP_MMC_ReadBlocks(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks, uint32_t Timeout)
{
  uint8_t sd_state = MSD_OK;

  if (HAL_MMC_ReadBlocks(&hmmc, (uint8_t *)pData, ReadAddr, NumOfBlocks, Timeout) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}

uint8_t BSP_MMC_WriteBlocks(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks, uint32_t Timeout)
{
  uint8_t sd_state = MSD_OK;

  if (HAL_MMC_WriteBlocks(&hmmc, (uint8_t *)pData, WriteAddr, NumOfBlocks, Timeout) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}

uint8_t BSP_MMC_ReadBlocks_DMA(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks)
{
  uint8_t sd_state = MSD_OK;

  if (HAL_MMC_ReadBlocks_DMA(&hmmc, (uint8_t *)pData, ReadAddr, NumOfBlocks) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}

uint8_t BSP_MMC_WriteBlocks_DMA(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks)
{
  uint8_t sd_state = MSD_OK;


  if (HAL_MMC_WriteBlocks_DMA(&hmmc, (uint8_t *)pData, WriteAddr, NumOfBlocks) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}

uint8_t BSP_MMC_Erase(uint32_t StartAddr, uint32_t EndAddr)
{
  uint8_t sd_state = MSD_OK;

  if (HAL_MMC_Erase(&hmmc, StartAddr, EndAddr) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}


void BSP_MMC_IRQHandler(void)
{
  HAL_MMC_IRQHandler(&hmmc);
}


void BSP_MMC_DMA_Tx_IRQHandler(void)
{
  HAL_DMA_IRQHandler(hmmc.hdmatx);
}


void BSP_MMC_DMA_Rx_IRQHandler(void)
{
  HAL_DMA_IRQHandler(hmmc.hdmarx);
}


uint8_t BSP_MMC_GetCardState(void)
{
  return ((HAL_MMC_GetCardState(&hmmc) == HAL_MMC_CARD_TRANSFER ) ? SD_TRANSFER_OK : SD_TRANSFER_BUSY);
}


void BSP_MMC_GetCardInfo(HAL_MMC_CardInfoTypeDef *CardInfo)
{
  HAL_MMC_GetCardInfo(&hmmc, CardInfo);
}
