#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <stdio.h>

int main(void) {
	irqInit();
	irqEnable(IRQ_VBLANK);

	SetMode(MODE_3 | BG2_ON);

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i) {
		((u16*)VRAM)[i] = 0xFF00;
	}

	while (1) {
		VBlankIntrWait();
	}
}


