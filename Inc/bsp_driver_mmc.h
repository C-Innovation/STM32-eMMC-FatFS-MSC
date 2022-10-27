/*
 * bsp_driver_mmc.h
 *
 *  Created on: 10 июн. 2019 г.
 *      Author: Ярослав
 */

#ifndef BSP_DRIVER_MMC_H_
#define BSP_DRIVER_MMC_H_

#include "stm32f4xx_hal.h"

#define BSP_MMC_CardInfo HAL_MMC_CardInfoTypeDef


#define   MSD_OK                        ((uint8_t)0x00)
#define   MSD_ERROR                     ((uint8_t)0x01)


#define   SD_TRANSFER_OK                ((uint8_t)0x00)
#define   SD_TRANSFER_BUSY              ((uint8_t)0x01)

#define SD_PRESENT               ((uint8_t)0x01)
#define SD_NOT_PRESENT           ((uint8_t)0x00)
#define SD_DATATIMEOUT           ((uint32_t)100000000)

uint8_t BSP_MMC_Init(void);
uint8_t BSP_MMC_ITConfig(void);
void    BSP_MMC_DetectIT(void);
void    BSP_MMC_DetectCallback(void);
uint8_t BSP_MMC_ReadBlocks(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks, uint32_t Timeout);
uint8_t BSP_MMC_WriteBlocks(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks, uint32_t Timeout);
uint8_t BSP_MMC_ReadBlocks_DMA(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks);
uint8_t BSP_MMC_WriteBlocks_DMA(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks);
uint8_t BSP_MMC_Erase(uint32_t StartAddr, uint32_t EndAddr);
void BSP_MMC_IRQHandler(void);
void BSP_MMC_DMA_Tx_IRQHandler(void);
void BSP_MMC_DMA_Rx_IRQHandler(void);
uint8_t BSP_MMC_GetCardState(void);
void    BSP_MMC_GetCardInfo(HAL_MMC_CardInfoTypeDef *CardInfo);
uint8_t BSP_MMC_IsDetected(void);

#endif /* BSP_DRIVER_MMC_H_ */
