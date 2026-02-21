#include "stdint.h"
#include "idt.h"

extern uint32_t isr_stub_table[];   // <-- CORRECT TYPE
extern void irq1_stub();            // keyboard IRQ stub

struct idt_entry idt[256];
struct idt_ptr idt_reg;

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low  = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].sel       = sel;
    idt[num].always0   = 0;
    idt[num].flags     = flags;
}

void idt_init() {
    idt_reg.limit = sizeof(idt) - 1;
    idt_reg.base  = (uint32_t)&idt;

    // Clear IDT
    for (int i = 0; i < 256; i++) {
        idt_set_gate(i, 0, 0, 0);
    }

    // CPU exceptions (0–31)
    for (int i = 0; i < 32; i++) {
        idt_set_gate(i, isr_stub_table[i], 0x08, 0x8E);
    }

    // Keyboard IRQ1 → interrupt vector 0x21
    idt_set_gate(0x21, (uint32_t)irq1_stub, 0x08, 0x8E);

    // Load IDT
    asm volatile("lidt (%0)" : : "r" (&idt_reg));
}
