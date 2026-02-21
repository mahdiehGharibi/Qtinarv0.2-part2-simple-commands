#include "stdint.h"
#include "vga.h"

void isr_handler(uint32_t int_no) {
    vga_puts("CPU Exception: ");

    // Convert exception number to simple 2-digit text
    char buf[4];
    buf[0] = '0' + (int_no / 10);
    buf[1] = '0' + (int_no % 10);
    buf[2] = '\n';
    buf[3] = 0;

    vga_puts(buf);

    // Halt the CPU forever
    while (1) asm volatile("hlt");
}
