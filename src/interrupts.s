.intel_syntax noprefix

# Exported symbols
.global isr_stub_table
.global irq1_stub

# Imported C handlers
.extern isr_handler
.extern irq_handler
.extern keyboard_handler

# ---------------------------------------------------------
# ISR STUB TABLE (32 entries)
# ---------------------------------------------------------

isr_stub_table:
    .long isr0
    .long isr1
    .long isr2
    .long isr3
    .long isr4
    .long isr5
    .long isr6
    .long isr7
    .long isr8
    .long isr9
    .long isr10
    .long isr11
    .long isr12
    .long isr13
    .long isr14
    .long isr15
    .long isr16
    .long isr17
    .long isr18
    .long isr19
    .long isr20
    .long isr21
    .long isr22
    .long isr23
    .long isr24
    .long isr25
    .long isr26
    .long isr27
    .long isr28
    .long isr29
    .long isr30
    .long isr31

# ---------------------------------------------------------
# Macro to generate ISR stubs
# ---------------------------------------------------------

.macro ISR num
isr\num:
    push \num              # push interrupt number
    call isr_handler       # call C handler
    add esp, 4             # pop pushed number
    iret
.endm

# Generate 32 ISR stubs
ISR 0
ISR 1
ISR 2
ISR 3
ISR 4
ISR 5
ISR 6
ISR 7
ISR 8
ISR 9
ISR 10
ISR 11
ISR 12
ISR 13
ISR 14
ISR 15
ISR 16
ISR 17
ISR 18
ISR 19
ISR 20
ISR 21
ISR 22
ISR 23
ISR 24
ISR 25
ISR 26
ISR 27
ISR 28
ISR 29
ISR 30
ISR 31

# ---------------------------------------------------------
# IRQ1 (Keyboard)
# ---------------------------------------------------------

irq1_stub:
    push 1                 # IRQ1 number (not used but consistent)
    call keyboard_handler  # call keyboard C handler
    add esp, 4
    iret
