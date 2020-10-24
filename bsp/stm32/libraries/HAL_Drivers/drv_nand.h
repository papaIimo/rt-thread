/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-06-30     thread-liu   first version
 */

#ifndef __DRV_NAND_H__
#define __DRV_NAND_H__

#include "board.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* stm32 config class */
struct stm32_nand_config
{
    volatile rt_uint16_t page_size;
    volatile rt_uint16_t pages_per_block;
    volatile rt_uint16_t plane_num;
    volatile rt_uint16_t oob_size;
    volatile rt_uint16_t oob_free;
    volatile rt_uint16_t block_start;
    volatile rt_uint16_t block_end;
};

/* nand flash status */
#ifndef NAND_READY
#define NAND_READY                      0x40 /* ready */
#endif
#define NAND_ECC1BITERR                 0x03 /* ECC 1bit err */
#define NAND_ECC2BITERR                 0x04 /* ECC 2bit or more err */

/* nand flash id */
#define MT29F8G08ABACAH4                0x64A690D3 /* id */
#define MT29F4G08ABADA			        0x569590dc	/* id */

#if defined(BSP_USING_MT29F8G08ABACAH4)
#define NAND_MAX_PAGE_SIZE              4096
#define NAND_ECC_SECTOR_SIZE            512
/* nand delay */
#define NAND_TWHR_DELAY                 25
#define NAND_TBERS_DELAY                4

#define NAND_ADDR                       ((rt_uint32_t)0x80000000) /* nand base address */
#define NAND_ADDR_AREA                  (*(__IO rt_uint8_t *)NAND_ADDR)
#define NAND_CMD_AREA                   (*(__IO rt_uint8_t *)(NAND_ADDR | 1 << 16))  /*  command */
#define NAND_DATA_AREA                  (*(__IO rt_uint8_t *)(NAND_ADDR | 1 << 17)) /*  data */
/* nand flash command */
#define NAND_READID                     0x90
#define NAND_FEATURE                    0xEF
#define NAND_RESET                      0xFF
#define NAND_READSTA                    0x70
#define NAND_AREA_A                     0x00
#define NAND_AREA_TRUE1                 0x30
#define NAND_WRITE0                     0x80
#define NAND_WRITE_TURE1                0x10
#define NAND_ERASE0                     0x60
#define NAND_ERASE1                     0xD0
#define NAND_MOVEDATA_CMD0              0x00
#define NAND_MOVEDATA_CMD1              0x35
#define NAND_MOVEDATA_CMD2              0x85
#define NAND_MOVEDATA_CMD3              0x10

#define NAND_FLASH_CONFIG            \
    {                                \
       .page_size       = 4096,      \
       .pages_per_block = 224,       \
       .plane_num       = 2,         \
       .oob_size        = 64,        \
       .oob_free        = 16, /* 64 - ((4096) * 3 / 256) */   \
       .block_start     = 0,         \
       .block_end       = 4095,      \
    }


#elif defined(BSP_USING_MT29F4G08ABADA)

#define NAND_MAX_PAGE_SIZE              4096
#define NAND_ECC_SECTOR_SIZE            512

/* nand delay */
#define NAND_TWHR_DELAY                 25
#define NAND_TBERS_DELAY                4

#define NAND_ADDR                       ((rt_uint32_t)0x80000000) /* nand base address */
#define NAND_ADDR_AREA                  (*(__IO rt_uint8_t *)NAND_ADDR)
#define NAND_SEND_CMD                   (*(__IO rt_uint8_t *)(NAND_ADDR | 1 << 16))  /*  send command */
#define NAND_SEND_ADDR                  (*(__IO rt_uint8_t *)(NAND_ADDR | 1 << 17))  /*  send addr */

/* nand flash command */
#define NAND_READID                     0x90
#define NAND_FEATURE                    0xEF
#define NAND_RESET                      0xFF
#define NAND_READSTA                    0x70
#define NAND_AREA_A                     0x00
#define NAND_AREA_TRUE1                 0x30
#define NAND_WRITE0                     0x80
#define NAND_WRITE_TURE1                0x10
#define NAND_ERASE0                     0x60
#define NAND_ERASE1                     0xD0
#define NAND_MOVEDATA_CMD0              0x00
#define NAND_MOVEDATA_CMD1              0x35
#define NAND_MOVEDATA_CMD2              0x85
#define NAND_MOVEDATA_CMD3              0x10
#define NAND_RANDOM_READ                0x05
#define NAND_START_READ                 0xE0
#define NAND_RANDOM_WRITE               0x85


#define NAND_FLASH_CONFIG            \
    {                                \
       .page_size       = 2048,      \
       .pages_per_block = 64,        \
       .plane_num       = 2,         \
       .oob_size        = 64,        \
       .oob_free        = 40, /* 64 - ((2048) * 3 / 256) */   \
       .block_start     = 0,         \
       .block_end       = 4095,      \
    }

#endif


#ifdef __cplusplus
}
#endif

#endif
