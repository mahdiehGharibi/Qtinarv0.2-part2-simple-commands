CC = gcc
AS = gcc
LD = ld

CFLAGS = -m32 -ffreestanding -fno-stack-protector -fno-pic -Wall -Wextra
ASFLAGS = -m32
LDFLAGS = -m elf_i386

SRC = src/boot.s src/gdt.c src/idt.c src/isr.c src/interrupts.s src/kernel.c src/vga.c
OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.s=.o)

all: kernel.bin

kernel.bin: $(OBJ) linker.ld
    $(LD) $(LDFLAGS) -T linker.ld -o kernel.bin $(OBJ)

run: kernel.bin
    qemu-system-i386 -kernel kernel.bin

clean:
    rm -f $(OBJ) kernel.bin
