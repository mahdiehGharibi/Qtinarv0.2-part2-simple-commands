.intel_syntax noprefix
.global start
.extern kernel_main

start:
    cli

    # GDT is already set by your gdt_init() in C
    call gdt_init
    call idt_init

    call kernel_main

.hang:
    cli
    hlt
    jmp .hang
