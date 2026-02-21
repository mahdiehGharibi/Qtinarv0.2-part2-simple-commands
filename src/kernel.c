#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "pic.h"

void kernel_main() {
    vga_clear();
    vga_puts("Qtinar OS booting...\n");

    gdt_init();
    vga_puts("GDT OK\n");

    idt_init();
    vga_puts("IDT OK\n");

    pic_remap();
    vga_puts("PIC remapped\n");

    pic_unmask_irq1();
    vga_puts("IRQ1 unmasked\n");

    vga_puts("Enabling interrupts...\n");
    asm volatile("sti");

    vga_puts("Interrupts enabled. Press keys...\n");

    while (1) asm volatile("hlt");
}
