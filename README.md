# QtinarOS v0.2 — Simple Commands, Keyboard Input, and Basic Shell

QtinarOS v0.2 is a small educational operating system written in C and Assembly for the x86 architecture. It boots with GRUB, sets up protected mode, configures interrupts, handles keyboard input, and provides a minimal command‑line interface with simple built‑in commands.

This project is part of a learning journey into OS development, focusing on understanding low‑level concepts such as memory layout, interrupts, drivers, and kernel structure.

![OutPut](https://github.com/mahdiehGharibi/Qtinarv0.2-part2-simple-commands/blob/be4b0ccfc6558cc7413676b1ab505e7f5ffe61aa/OutPut.png)

## ✨ Features

### CPU & Boot
- Multiboot‑compatible kernel
- Custom linker script and boot sequence
- GDT (Global Descriptor Table) setup
- IDT (Interrupt Descriptor Table) setup
- ISR (Interrupt Service Routines) and IRQ handling
- PIC (Programmable Interrupt Controller) remapping

### Drivers
- VGA text‑mode screen driver
- Keyboard driver with scancode handling
- Working backspace support
- Dynamic input buffer (no typing limit)

### Kernel & Shell
- Simple command interpreter
- Built‑in commands:
  - `help` — list available commands
  - `clear` — clear the screen
  - `echo <text>` — print text
- Clean prompt (`> `)
- Automatic command execution on Enter



## 📁 Project Structure
```
src/
├── cpu/          # GDT, IDT, ISR, IRQ, PIC, ports
├── drivers/      # Screen, keyboard, printing
├── kernel/       # Input system, commands, main kernel
└── libc/         # Minimal C library (string, memory)
```



## 🛠️ Build & Run

### Requirements
- GCC (with 32‑bit support)
- binutils (ld, objdump, etc.)
- GRUB tools (`grub-mkrescue`)
- QEMU (or any x86 emulator)

### Build Commands

(Your full build commands go here — unchanged)



## 🎯 Goals of This Project

QtinarOS is a learning‑focused OS. The goals include:

- Understanding how an OS boots
- Learning low‑level C and Assembly
- Writing hardware drivers from scratch
- Building a minimal shell
- Exploring memory management and interrupts



## 🚀 Roadmap (Future Work)

- Scrolling terminal
- Colored text output
- Command history (↑ ↓ keys)
- Timer (PIT) driver
- Paging and memory management
- File system support
- User programs
- Multitasking
