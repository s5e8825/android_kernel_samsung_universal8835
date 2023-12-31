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

#include "is-device-ischain.h"
#include "is-device-sensor.h"
#include "is-subdev-ctrl.h"
#include "is-config.h"
#include "is-param.h"
#include "is-video.h"
#include "is-type.h"
#include "is-hw.h"

static int __lme_dma_cfg(struct is_device_ischain *device,
	struct is_subdev *leader,
	struct is_frame *ldr_frame,
	struct camera2_node *node,
	struct param_lme_dma *dma,
	u32 pindex,
	IS_DECLARE_PMAP(pmap))
{
	struct is_fmt *fmt;
	struct param_control *control;
	struct is_crop *incrop, *otcrop;
	u32 hw_msb, hw_order, hw_plane;
	u32 hw_bitwidth = DMA_INOUT_BIT_WIDTH_8BIT;
	int ret = 0;
	u32 i;

	FIMC_BUG(!leader);
	FIMC_BUG(!device);
	FIMC_BUG(!ldr_frame);
	FIMC_BUG(!node);

	if (!node->request) {
		switch (node->vid) {
		case IS_VIDEO_LME0_NUM:
		case IS_VIDEO_LME1_NUM:
			dma->cur_input_cmd = DMA_INPUT_COMMAND_DISABLE;
			break;
		case IS_VIDEO_LME0S_NUM:
		case IS_VIDEO_LME1S_NUM:
			dma->prev_input_cmd = DMA_INPUT_COMMAND_DISABLE;
			for (i = 0; i < IS_MAX_PLANES; i++)
				ldr_frame->lmesKTargetAddress[i] = 0;
			break;
		case IS_VIDEO_LME0C_NUM:
		case IS_VIDEO_LME1C_NUM:
			dma->output_cmd = DMA_OUTPUT_COMMAND_DISABLE;
			for (i = 0; i < IS_MAX_PLANES; i++)
				ldr_frame->lmecKTargetAddress[i] = 0;
			break;
		case IS_VIDEO_LME0M_NUM:
		case IS_VIDEO_LME1M_NUM:
			dma->output_cmd = DMA_OUTPUT_COMMAND_DISABLE;
			break;
		default:
			break;
		}

		set_bit(PARAM_LME_DMA, pmap);

		return 0;
	}

	incrop = (struct is_crop *)node->input.cropRegion;
	if (IS_NULL_CROP(incrop)) {
		merr("incrop is NULL", device);
		return -EINVAL;
	}

	otcrop = (struct is_crop *)node->output.cropRegion;
	if (IS_NULL_CROP(otcrop)) {
		merr("otcrop is NULL", device);
		return -EINVAL;
	}

	fmt = is_find_format(node->pixelformat, node->flags);
	if (!fmt) {
		merr("pixel format(0x%x) is not found", device, node->pixelformat);
		return -EINVAL;
	}

	hw_msb = hw_bitwidth - 1;
	hw_order = fmt->hw_order;
	hw_plane = fmt->hw_plane;

	control = is_itf_g_param(device, ldr_frame, PARAM_LME_CONTROL);
	control->cmd = CONTROL_COMMAND_START;
	control->bypass = CONTROL_BYPASS_DISABLE;

	switch (node->vid) {
	case IS_VIDEO_LME0_NUM:
	case IS_VIDEO_LME1_NUM:
		set_bit(PARAM_LME_CONTROL, pmap);

		dma = is_itf_g_param(device, ldr_frame, PARAM_LME_DMA);
		dma->cur_input_cmd = DMA_INPUT_COMMAND_ENABLE;
		dma->input_format = DMA_INOUT_FORMAT_Y;
		dma->input_bitwidth = hw_bitwidth;
		dma->input_order = hw_order;
		dma->input_msb = hw_msb;
		dma->input_plane = hw_plane;
		dma->cur_input_width = incrop->w;
		dma->cur_input_height = incrop->h;

		set_bit(pindex, pmap);

		break;
	case IS_VIDEO_LME0S_NUM:
	case IS_VIDEO_LME1S_NUM:
		dma->prev_input_cmd = DMA_INPUT_COMMAND_ENABLE;
		dma->prev_input_width = incrop->w;
		dma->prev_input_height = incrop->h;

		break;
	case IS_VIDEO_LME0C_NUM:
	case IS_VIDEO_LME1C_NUM:
		dma->output_cmd = DMA_INPUT_COMMAND_ENABLE;
		dma->output_format = DMA_INOUT_FORMAT_Y;
		dma->output_order = hw_order;
		dma->output_bitwidth = hw_bitwidth;
		dma->output_plane = hw_plane;
		dma->output_msb = hw_msb;
		dma->output_width = otcrop->w;
		dma->output_height = otcrop->h;
		break;
	}

	return ret;
}

static int is_ischain_lme_tag(struct is_subdev *subdev,
	void *device_data,
	struct is_frame *frame,
	struct camera2_node *node)
{
	int ret = 0;
	struct lme_param *lme_param;
	struct is_crop *incrop, *otcrop;
	struct is_subdev *leader;
	struct is_device_ischain *device;
	IS_DECLARE_PMAP(pmap);
	struct is_queue *queue;
	struct camera2_node *out_node = NULL;
	struct camera2_node *cap_node = NULL;
	struct is_sub_frame *sframe;
	struct param_lme_dma *dma = NULL;
	u32 *targetAddr;
	u64 *targetAddr_k;
	int j, i;

	device = (struct is_device_ischain *)device_data;

	FIMC_BUG(!subdev);
	FIMC_BUG(!device);
	FIMC_BUG(!device->is_region);
	FIMC_BUG(!frame);

	mdbgs_ischain(4, "LME TAG\n", device);

	incrop = (struct is_crop *)node->input.cropRegion;
	otcrop = (struct is_crop *)node->output.cropRegion;

	leader = subdev->leader;
	IS_INIT_PMAP(pmap);
	lme_param = &device->is_region->parameter.lme;

	if (IS_ENABLED(LOGICAL_VIDEO_NODE)) {
		queue = GET_SUBDEV_QUEUE(leader);
		if (!queue) {
			merr("queue is NULL", device);
			ret = -EINVAL;
			goto p_err;
		}

		out_node = &frame->shot_ext->node_group.leader;
		dma = is_itf_g_param(device, frame, PARAM_LME_DMA);
		ret = __lme_dma_cfg(device, subdev, frame, out_node, dma,
				PARAM_LME_DMA, pmap);

		for (i = 0; i < CAPTURE_NODE_MAX; i++) {
			cap_node = &frame->shot_ext->node_group.capture[i];
			if (!cap_node->vid) {
				if (i == 0) {
					/* LMEC capture node is zero */
					dma->output_cmd = DMA_OUTPUT_COMMAND_DISABLE;

					set_bit(PARAM_LME_DMA, pmap);
				}
				continue;
			}

			ret = __lme_dma_cfg(device, subdev, frame, cap_node,
					dma, PARAM_LME_DMA, pmap);
		}

		/* buffer tagging */
		for (i = 0; i < CAPTURE_NODE_MAX; i++) {
			sframe = &frame->cap_node.sframe[i];
			if (!sframe->id)
				continue;

			/* TODO: consider Sensor and PDP */
			if ((sframe->id >= IS_VIDEO_SS0VC0_NUM) &&
					(sframe->id <= IS_VIDEO_PAF3S_NUM))
				continue;

			targetAddr = NULL;
			targetAddr_k = NULL;
			ret = is_hw_get_capture_slot(frame, &targetAddr,
					&targetAddr_k, sframe->id);
			if (ret) {
				mrerr("Invalid capture slot(%d)", device, frame,
						sframe->id);
				return -EINVAL;
			}

			if (targetAddr) {
				for (j = 0; j < sframe->num_planes; j++)
					targetAddr[j] = sframe->dva[j];
			}

			if (targetAddr_k) {
				/* IS_VIDEO_LME0C_NUM,
				 * IS_VIDEO_LME0S_NUM,
				 * IS_VIDEO_LME0M_NUM */
				for (j = 0; j < sframe->num_planes; j++)
					targetAddr_k[j] = sframe->kva[j];
			}
		}

		ret = is_itf_s_param(device, frame, pmap);
		if (ret) {
			mrerr("is_itf_s_param is fail(%d)", device, frame, ret);
			goto p_err;
		}

		return ret;
	}

p_err:
	return ret;
}

const struct is_subdev_ops is_subdev_lme_ops = {
	.bypass			= NULL,
	.cfg			= is_ischain_lme_cfg,
	.tag			= is_ischain_lme_tag,
};
