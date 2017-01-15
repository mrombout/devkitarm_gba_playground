#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <stdio.h>

int main(void) {
	irqInit();
	irqEnable(IRQ_VBLANK);

	consoleDemoInit();

	iprintf("Hello World!");

	while (1) {
		VBlankIntrWait();
	}
}


