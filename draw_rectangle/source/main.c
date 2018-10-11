#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <stdio.h>

void drawPixel(int x, int y, u16 color) {
	((u16*)VRAM)[y * SCREEN_WIDTH + x] = color;
}

void drawRectangle(int left, int top, int width, int height, u16 color) {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			drawPixel(x + left, y + top, color);
		}
	}
}

int main(void) {
	irqInit();
	irqEnable(IRQ_VBLANK);

	SetMode(MODE_3 | BG2_ON);

	drawRectangle(10, 10, 10, 10, 0xFFFF);

	while (1) {
		VBlankIntrWait();
	}
}

