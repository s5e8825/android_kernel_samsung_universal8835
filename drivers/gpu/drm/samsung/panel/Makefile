#
# Copyright (c) 2013 Samsung Electronics Co., Ltd.
#		http://www.samsung.com
#
# Licensed under GPLv2
#

subdir-ccflags-y := -I$(srctree) -I$(srctree)/$(src)

mcd-panel-y += timenval.o \
				abd.o \
				util.o \
				panel_lib.o \
				maptbl.o \
				panel_sequence.o \
				panel_delay.o \
				panel_packet.o \
				panel_resource.o \
				panel_dump.o \
				panel.o \
				panel_bl.o \
				dimming.o \
				panel_gpio.o \
				panel_regulator.o \
				panel_drv_ioctl.o \
				panel_drv.o \
				panel_irc.o \
				panel_vrr.o \
				panel_power_ctrl.o \
				panel_obj.o \
				panel_mutex.o

mcd-panel-$(CONFIG_PANEL_DISPLAY_MODE) += panel_modes.o
mcd-panel-$(CONFIG_EXYNOS_DECON_LCD_SYSFS) += sysfs.o
mcd-panel-$(CONFIG_EXYNOS_DECON_MDNIE_LITE) += mdnie.o
mcd-panel-$(CONFIG_PANEL_DEBUG) += panel_debug.o
mcd-panel-$(CONFIG_EXTEND_LIVE_CLOCK) += aod/aod_drv.o
mcd-panel-$(CONFIG_PANEL_FREQ_HOP) += panel_freq_hop.o
mcd-panel-$(CONFIG_SUPPORT_MAFPC) += mafpc/mafpc_drv.o
mcd-panel-$(CONFIG_DISPLAY_USE_INFO) += dpui.o
mcd-panel-$(CONFIG_EXYNOS_DECON_LCD_COPR) += copr.o
mcd-panel-$(CONFIG_SUPPORT_POC_SPI) += panel_poc.o panel_spi.o
mcd-panel-$(CONFIG_MCD_PANEL_I2C) += panel_i2c.o
mcd-panel-$(CONFIG_MCD_PANEL_BLIC) += panel_blic.o

mcd-panel-$(CONFIG_MCD_PANEL_JSON) += \
	ezop/jsmn.o \
	ezop/json.o \
	ezop/json_writer.o \
	ezop/json_reader.o \
	ezop/panel_json.o

obj-$(CONFIG_MCD_PANEL) += mcd-panel.o

subdir-ccflags-$(CONFIG_SEC_KUNIT) += \
    -Wframe-larger-than=8192 \
    -Wno-unused-variable \
    -Wno-unused-function \
    -Wno-missing-braces \
    -Wno-implicit-fallthrough \
    -Wno-format

