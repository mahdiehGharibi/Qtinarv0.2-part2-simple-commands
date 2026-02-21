.intel_syntax noprefix
.global multiboot_header

.section .multiboot
.align 4

multiboot_header:
    .long 0x1BADB002        # magic
    .long 0x0               # flags
    .long -(0x1BADB002+0x0) # checksum
