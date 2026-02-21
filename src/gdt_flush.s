.intel_syntax noprefix
.global gdt_flush

gdt_flush:
    lgdt [eax]        # load GDT from pointer in eax
    mov ax, 0x10      # reload data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush2   # far jump to reload CS

flush2:
    ret
