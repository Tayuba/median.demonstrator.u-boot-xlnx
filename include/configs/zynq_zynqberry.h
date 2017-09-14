/*
 * (C) Copyright 2012 Xilinx
 * (C) Copyright 2014 Digilent Inc.
 *
 * Configuration for Zynq Development Board - ZYBO
 * See zynq-common.h for Zynq common configs
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_ZYNQ_ZYNQBERRY_H
#define __CONFIG_ZYNQ_ZYNQBERRY_H

#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_EXTRA_ENV_SETTINGS	\
	"kernel_image=uImage\0"	\
	"kernel_load_address=0x2080000\0" \
	"devicetree_image=zynq-zynqberry.dtb\0"	\
	"devicetree_load_address=0x2000000\0"	\
	"kernel_size=0x500000\0"	\
	"devicetree_size=0x20000\0"	\
	"boot_size=0xF00000\0"	\
	"fdt_high=0x20000000\0"	\
	"loadbootenv=load mmc 0 ${loadbootenv_addr} ${bootenv}\0" \
	"sdboot=if mmcinfo; then " \
			"echo Copying Linux from SD to RAM... && " \
			"load mmc 0 ${kernel_load_address} ${kernel_image} && " \
			"load mmc 0 ${devicetree_load_address} ${devicetree_image} && " \
			"bootm ${kernel_load_address} - ${devicetree_load_address}; " \
		"fi\0"

#include <configs/zynq-common.h>

#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND		"run sdboot"


#endif /* __CONFIG_ZYNQ_ZYNQBERRY_H */
