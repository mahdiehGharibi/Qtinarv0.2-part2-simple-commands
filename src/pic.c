#include "stdint.h"
#include "io.h"

void pic_remap() {
    outb(0x20, 0x11);
    outb(0xA0, 0x11);

    outb(0x21, 0x20);
    outb(0xA1, 0x28);

    outb(0x21, 0x04);
    outb(0xA1, 0x02);

    outb(0x21, 0x01);
    outb(0xA1, 0x01);

    // Mask all IRQs; we'll unmask only what we want
    outb(0x21, 0xFF);
    outb(0xA1, 0xFF);
}

void pic_unmask_irq1() {
    uint8_t mask = inb(0x21);
    mask &= ~(1 << 1);      // clear bit 1 → enable IRQ1 only
    outb(0x21, mask);
}
