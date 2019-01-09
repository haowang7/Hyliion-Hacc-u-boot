
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <spl.h>
#include <serial.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/clk_synthesizer.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mem.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <asm/omap_common.h>
#include <asm/omap_sec_common.h>
#include <asm/omap_mmc.h>
#include <asm/davinci_rtc.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <power/tps65217.h>
#include <power/tps65910.h>
#include <environment.h>
#include <watchdog.h>
#include <environment.h>
#include "../common/board_detect.h"
#include "board.h"

//blinker test
void blinker(void)
{
	static int state;//added for gpio test
//	1=2;
	unsigned char i,pinid;

//		pinid = 1*32+21;
	for(i=17;i<=22;i++)
	{
		pinid=1*32+i;
		if(!(gpio_request(pinid, "led")))
		{
			gpio_direction_output(pinid,1);
			printf("group %d gpio %d requested\n", pinid / 32, pinid - (pinid/32));
		}
	}

	pinid = 1*32+24;
	if(!(gpio_request(pinid, "led")))
	{
		gpio_direction_output(pinid,1);
		printf("group %d gpio %d requested\n", pinid / 32, pinid - (pinid/32));
	}
	//testing u-boot io
	while(1)
	{
//		1=2;
	//gpio_set_value(150, 0);
	for(i=17;i<=22;i++)
	{
		pinid = 1*32+i;
		state = gpio_get_value(pinid);
		gpio_direction_output(pinid, !state);
		printf("gpio %d toggle\n",i);
	}
	pinid = 1*32+24;
	state = gpio_get_value(pinid);
	gpio_direction_output(pinid, !state);
	printf("gpio %d toggle\n",i);
	udelay(2000000);
	}
}

