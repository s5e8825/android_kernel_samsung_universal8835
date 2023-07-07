// SPDX-License-Identifier: GPL-2.0
/*
 * Samsung Exynos SoC series Pablo driver
 *
 * Copyright (c) 2020 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef IS_CONFIG_H
#define IS_CONFIG_H

#include <linux/version.h>
#include "is-common-config.h"
#include "is-vendor-config.h"

/*
 * =================================================================================================
 * CONFIG - GLOBAL OPTIONS
 * =================================================================================================
 */
#define IS_SENSOR_COUNT		6
#define IS_STREAM_COUNT		12

/*
 * =================================================================================================
 * CONFIG - Chain IP configurations
 * =================================================================================================
 */
/* Sensor VC */
#define SOC_SSVC0	1
#define SOC_SSVC1	1
#define SOC_SSVC2	1
#define SOC_SSVC3	1

/* 3AA0 */
#define SOC_30S		1
#define SOC_30C		1
#define SOC_30P		1
#define SOC_30F		1
#define SOC_30G		1
#define SOC_30O		1
#define SOC_ZSL_STRIP_DMA0

/* 3AA1 */
#define SOC_31S		1
#define SOC_31C		1
#define SOC_31P		1
#define SOC_31F		1
#define SOC_31G		1
#define SOC_31O		1
#define SOC_ZSL_STRIP_DMA1

/* 3AA2 */
#define SOC_32S		1
#define SOC_32C		1
#define SOC_32P		1
#define SOC_32F		1
#define SOC_32G		1
#define SOC_32O		1
#define SOC_ZSL_STRIP_DMA2

/* TNR */
#define SOC_TNR		1
#define SOC_TNR_MERGER	1

/* ITP0 */
#define SOC_I0S		1
#define SOC_DNS0S	1
#define SOC_I0C		1

/* MEIP/ORB-MCH */
#define SOC_ME0S	1
#define SOC_ME0C	1
#define SOC_ME1S	1
#define SOC_ME1C	1
#define SOC_ORB0C	1

/* MCSC */
#define SOC_MCS		1
#define SOC_MCS0	1

/* YUVPP */
#define SOC_YPP		1

/* LME0 : ME GROUP */
#define SOC_LME0	1
#define SOC_LME0S	1
#define SOC_LME0C	1

/* LME1 : ME GROUP */
#define SOC_LME1	1
#define SOC_LME1S	1
#define SOC_LME1C	1

#define YPP_COMP_BLOCK_WIDTH		256
#define YPP_COMP_BLOCK_HEIGHT		1

#define GDC_COMP_BLOCK_WIDTH		32
#define GDC_COMP_BLOCK_HEIGHT		4

#define COMP_LOSSYBYTE32NUM_256X1_U10	5

#define DEV_HW_ISP0_ID		DEV_HW_ISP0

#define CSIS_OTF_CH_LC_NUM		4

/*
 * =================================================================================================
 * CONFIG - SW configurations
 * =================================================================================================
 */

#define LOGICAL_VIDEO_NODE	1

#define CHAIN_STRIPE_PROCESSING	1
#define RGB2YUV422_MARGIN_WIDTH	4
#define MCSC_MARGIN_WIDTH		96
#define YUVNR_MARGIN_WIDTH		144
#define STRIPE_MARGIN_WIDTH		256
#define STRIPE_WIDTH_ALIGN		512
#define STRIPE_RATIO_PRECISION		1000
#define STRIPE_MCSC_MARGIN_WIDTH	(MCSC_MARGIN_WIDTH + RGB2YUV422_MARGIN_WIDTH)
#define ENABLE_TNR
#define ENABLE_ORBMCH	1

#if IS_ENABLED(LOGICAL_VIDEO_NODE)
#define ENABLE_ORBDS
#define ENABLE_LMEDS	/* only for interface sync */
#endif

#define ENABLE_HF
#define ENABLE_RGB_REPROCESSING
#define ENABLE_SC_MAP
#define ENABLE_10BIT_MCSC
#define ENABLE_DJAG_IN_MCSC
#define ENABLE_MCSC_CENTER_CROP
#define USE_MCSC_STRIP_OUT_CROP		/* use for MCSC stripe */
#define USE_MCFP_MOTION_INTERFACE	1
#define USE_MCSC_H_V_COEFF		/* support different u,v coefficient */
#define USE_YPP_INTERFACE		1
#define USE_HF_INTERFACE		1

#define USE_ONE_BINARY
#define USE_RTA_BINARY
/* #define DISABLE_DDK_HEAP_FREE */
#define USE_BINARY_PADDING_DATA_ADDED	/* for DDK signature */
#define USE_DDK_SHUT_DOWN_FUNC
#define ENABLE_IRQ_MULTI_TARGET
#define ENABLE_3AA_LIC_OFFSET	1
#define PDP_RDMA_LINE_GAP      (0x128)
#define IS_MAX_HW_3AA_SRAM		(16383)

#define PDP_RDMA_MO_LIMIT		1

#define ENABLE_MODECHANGE_CAPTURE

#define CSIWDMA_VC1_FORMAT_WA	1

/* #define ENABLE_SKIP_PER_FRAME_MAP */
#define YPP_DDK_LIB_CALL	1

/* For ME group, use ORBMCH IP instead of LME IP. */
#define USE_ORBMCH_FOR_ME

#define USE_ORBMCH_WA

/*
 * PDP0: RDMA
 * PDP1: RDMA
 * PDP2: RDMA
 * 3AA0: 3AA0, ZSL/STRIP DMA0, MEIP0
 * 3AA1: 3AA1, ZSL/STRIP DMA1, MEIP1
 * 3AA2: 3AA2, ZSL/STRIP DMA2, MEIP2
 * ITP0: TNR, ITP0, DNS0
 * MCSC0:
 *
 */
#define HW_SLOT_MAX            (11)
#define valid_hw_slot_id(slot_id) \
	(slot_id >= 0 && slot_id < HW_SLOT_MAX)
#define HW_NUM_LIB_OFFSET	(2)
/* #define SKIP_SETFILE_LOAD */
/* #define SKIP_LIB_LOAD */

#define USE_SENSOR_IF_DPHY

#ifdef CONFIG_SOC_S5E9815
#define DYNAMIC_HEAP_FOR_DDK_RTA	1
#endif

/* FIMC-IS task priority setting */
#define TASK_SENSOR_WORK_PRIO		(IS_MAX_PRIO - 48) /* 52 */
#define TASK_GRP_OTF_INPUT_PRIO		(IS_MAX_PRIO - 49) /* 51 */
#define TASK_GRP_DMA_INPUT_PRIO		(IS_MAX_PRIO - 50) /* 50 */
#define TASK_MSHOT_WORK_PRIO		(IS_MAX_PRIO - 43) /* 57 */
#define TASK_LIB_OTF_PRIO		(IS_MAX_PRIO - 44) /* 56 */
#define TASK_LIB_AF_PRIO		(IS_MAX_PRIO - 45) /* 55 */
#define TASK_LIB_ISP_DMA_PRIO		(IS_MAX_PRIO - 46) /* 54 */
#define TASK_LIB_3AA_DMA_PRIO		(IS_MAX_PRIO - 47) /* 53 */
#define TASK_LIB_AA_PRIO		(IS_MAX_PRIO - 48) /* 52 */
#define TASK_LIB_RTA_PRIO		(IS_MAX_PRIO - 49) /* 51 */
#define TASK_LIB_VRA_PRIO		(IS_MAX_PRIO - 45) /* 55 */

/* EXTRA chain for 3AA and ITP
 * Each IP has 4 slot
 * 3AA: 0~3	ITP: 0~3
 * MEIP: 4~7	MCFP0: 4~7
 * DMA: 8~11	DNS: 8~11
 * LME: 8~11	MCFP1: 8~11
 */
#define LIC_CHAIN_OFFSET	(0x10000)
#define LIC_CHAIN_NUM		(2)
#define LIC_CHAIN_OFFSET_NUM	(6)

#define SBWC_BASE_ALIGN_MASK	(0x4)	/* 0x0: 32B_ALIGN, 0x4: 64B_ALIGN */

#if IS_ENABLED(LOGICAL_VIDEO_NODE) || !IS_ENABLED(SOC_VRA)
#define PARAM_FD_OTF_INPUT	0
#endif

/*
 * =================================================================================================
 * CONFIG - FEATURE ENABLE
 * =================================================================================================
 */
#define IS_MAX_TASK		(40)

#define HW_TIMEOUT_PANIC_ENABLE
#ifdef HW_TIMEOUT_PANIC_ENABLE
#define CHECK_TIMEOUT_PANIC_HW(id)	((id == DEV_HW_ISP0) || \
				(id == DEV_HW_LME0))
#endif
#if defined(CONFIG_ARM_EXYNOS_DEVFREQ)
#define CONFIG_IS_BUS_DEVFREQ
#endif

#if defined(OVERFLOW_PANIC_ENABLE_ISCHAIN)
#define DDK_OVERFLOW_RECOVERY		(0)	/* 0: do not execute recovery, 1: execute recovery */
#else
#define DDK_OVERFLOW_RECOVERY		(1)	/* 0: do not execute recovery, 1: execute recovery */
#endif

#define CAPTURE_NODE_MAX		12
#define OTF_YUV_FORMAT			(OTF_INPUT_FORMAT_YUV422)
#define MSB_OF_3AA_DMA_OUT		(11)
#define MSB_OF_DNG_DMA_OUT		(9)
/* #define USE_YUV_RANGE_BY_ISP */
/* #define ENABLE_3AA_DMA_CROP */

/* use bcrop1 to support DNG capture for pure bayer reporcessing */
#define USE_3AA_CROP_AFTER_BDS

/* #define ENABLE_ULTRA_FAST_SHOT */
#define ENABLE_HWFC
#define TPU_COMPRESSOR
#define USE_I2C_LOCK
#define SENSOR_REQUEST_DELAY		2

#ifdef ENABLE_IRQ_MULTI_TARGET
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 20, 0))
#define IS_HW_IRQ_FLAG     0
#else
#define IS_HW_IRQ_FLAG     IRQF_GIC_MULTI_TARGET
#endif
#define IRQ_MULTI_TARGET_CL0 1
#else
#define IS_HW_IRQ_FLAG     0
#endif

/* #define ENABLE_EARLY_SHOT */
#define SUPPORT_HW_FRO(id)		0
#define FULL_OTF_TAIL_GROUP_ID		GROUP_ID_MCS0

#if defined(USE_I2C_LOCK)
#define I2C_MUTEX_LOCK(lock)	\
	({if (!in_atomic())	\
		mutex_lock(lock);})
#define I2C_MUTEX_UNLOCK(lock)	\
	({if (!in_atomic())	\
		mutex_unlock(lock);})
#else
#define I2C_MUTEX_LOCK(lock)
#define I2C_MUTEX_UNLOCK(lock)
#endif

#define ENABLE_DBG_EVENT_PRINT
/* #define ENABLE_DBG_CLK_PRINT */

#ifdef SECURE_CAMERA_IRIS
#undef SECURE_CAMERA_IRIS
#endif
/* #define SECURE_CAMERA_FACE */	/* For face Detection and face authentication */
#define SECURE_CAMERA_CH		((1 << CSI_ID_C) | (1 << CSI_ID_E))
#define SECURE_CAMERA_HEAP_ID		(11)
#define SECURE_CAMERA_MEM_ADDR		(0x96000000)	/* secure_camera_heap */
#define SECURE_CAMERA_MEM_SIZE		(0x02800000)
#define NON_SECURE_CAMERA_MEM_ADDR	(0x0)	/* camera_heap */
#define NON_SECURE_CAMERA_MEM_SIZE	(0x0)
#define ION_EXYNOS_FLAG_PROTECTED	BIT(16)
#define ION_EXYNOS_FLAG_IOVA_EXTENSION	BIT(20)

#undef SECURE_CAMERA_FACE_SEQ_CHK	/* To check sequence before applying secure protection */

#define USE_NEW_PER_FRAME_CONTROL

#define ENABLE_HWACG_CONTROL

#define BDS_DVFS
/* #define ENABLE_VIRTUAL_OTF */
/* #define ENABLE_DCF */

/* #define ENABLE_PDP_STAT_DMA */

#define USE_PDP_LINE_INTR_FOR_PDAF	0
#define USE_DEBUG_PD_DUMP	0
#define DEBUG_PD_DUMP_CH	0  /* set a bit corresponding to each channel */


/* init AWB */
#define INIT_AWB		1
#define WB_GAIN_COUNT		(4)
#define INIT_AWB_COUNT_REAR	(3)
#define INIT_AWB_COUNT_FRONT	(8)

/* use CIS global work for enhance launching time */
#define USE_CIS_GLOBAL_WORK	1

#define USE_CAMIF_FIX_UP	1
#define CHAIN_TAG_SENSOR_IN_SOFTIRQ_CONTEXT	0
#define CHAIN_TAG_VC0_DMA_IN_HARDIRQ_CONTEXT	1

#define USE_SKIP_DUMP_LIC_OVERFLOW	1

/* default LIC value for 9830 */
/*
 * MAX: 16383
 * CTX0: 25M(5804), 25M(5804), 8M (3328)
 * CTX1: 25M(5804), 25M(5804), 8M (3328)
 */
#define DEFAULT_LIC_CTX0_OFFSET0	(5824)
#define DEFAULT_LIC_CTX0_OFFSET1	(5824)
#define DEFAULT_LIC_CTX1_OFFSET0	(5824)
#define DEFAULT_LIC_CTX1_OFFSET1	(5824)

#define CONFIG_VOTF_ONESHOT	0	/* oneshot mode is used when using VOTF in PDP input.  */
#define VOTF_BACK_FIRST_OFF	0	/* This is only for v8.1. next AP don't have to use thie. */
#define USE_VOTF_AXI_APB

/* BTS */
/* #define DISABLE_BTS_CALC	*/ /* This is only for v8.1. next AP don't have to use this */

#define THROTTLING_MIF_ENABLE   1
#define THROTTLING_INT_ENABLE 0
#define THROTTLING_INTCAM_ENABLE 0
#define THROTTLING_MIF_LEVEL		(1539000)
#define THROTTLING_INTCAM_LEVEL	(640000)
#define THROTTLING_INT_LEVEL		(400000)

#define AP_PHY_LDO_ALL_SAME  	1

#define SYNC_SHOT_ALWAYS	/* This is a feature for reducing late shot. */

#define CHECK_TAD_ID(vid)	((vid == IS_VIDEO_30D_NUM) || \
				(vid == IS_VIDEO_31D_NUM) || \
				(vid == IS_VIDEO_32D_NUM))
#define CHECK_TAH_ID(vid)	((vid == IS_VIDEO_30H_NUM) || \
				(vid == IS_VIDEO_31H_NUM) || \
				(vid == IS_VIDEO_32H_NUM))

#define CHECK_NEED_KVADDR_ID(vid)					\
				(((vid) == IS_VIDEO_LME0C_NUM)		\
				|| ((vid) == IS_VIDEO_LME1C_NUM)	\
				|| ((vid) == IS_VIDEO_LME0S_NUM)	\
				|| ((vid) == IS_VIDEO_LME1S_NUM)	\
				|| ((vid) == IS_VIDEO_LME0M_NUM)	\
				|| ((vid) == IS_VIDEO_LME1M_NUM)	\
				|| ((vid) == IS_VIDEO_IMM_NUM)		\
				)

#define MCSC_HF_ID	(IS_VIDEO_M5P_NUM)

#define CHECK_YPP_NOISE_RDMA_DISALBE(exynos_soc_info)	\
		(exynos_soc_info.main_rev >= 0 && exynos_soc_info.sub_rev >= 1)

#define CLOGGING		1
/*
 * ======================================================
 * CONFIG - Interface version configs
 * ======================================================
 */

#define SETFILE_VERSION_INFO_HEADER1	(0xF85A20B4)
#define SETFILE_VERSION_INFO_HEADER2	(0xCA539ADF)

#define META_ITF_VER_20192003

#define ENABLE_FPSIMD_FOR_USER
#define VH_FPSIMD_API

#define USE_DDK_INTF_LIC_OFFSET

#define USE_FLIP_WIDE_SENSOR
#endif /* #ifndef IS_CONFIG_H */
