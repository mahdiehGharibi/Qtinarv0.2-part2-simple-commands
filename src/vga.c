#include "stdint.h"
#include "vga.h"

static uint16_t *vga = (uint16_t*)0xB8000;
static uint8_t row = 0, col = 0;
static uint8_t color = 0x0F;

void vga_clear() {
    for (int i = 0; i < 80 * 25; i++)
        vga[i] = (color << 8) | ' ';
}

void vga_puts(const char *str) {
    while (*str) {
        if (*str == '\n') {
            row++;
            col = 0;
        } else {
            vga[row * 80 + col] = (color << 8) | *str;
            col++;
        }
        str++;
    }
}
