#include "stdint.h"
#include "io.h"
#include "vga.h"

void keyboard_handler() {
    uint8_t sc = inb(0x60);
    vga_puts("key\n");
    outb(0x20, 0x20);
}
