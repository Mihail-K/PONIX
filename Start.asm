
.file "Start.asm"
.extern Kmain

.set FLAGS, 1 + 2
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.set PRESENT, 1 << 0
.set READWRITE, 1 << 1
.set LARGEPAGE, 1 << 7

.set VOFFSET, 0xC0000000

// Multiboot Header
.section .mboot
.align 4

MbootHeader:
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

// Kernel Page Directory
.section .data
.align 4096

.global PageDirectory
PageDirectory:
	.long PRESENT | READWRITE | LARGEPAGE
	.fill 768 - 1, 4, 0
	.long PRESENT | READWRITE | LARGEPAGE
	.fill 1024 - 786, 4, 0

// Start (Lower Half)
.section .textlow
.align 4

.global StartLow
.type StartLow, @function
StartLow:
	cli

	movl $(PageDirectory - VOFFSET), %ecx
	movl %ecx, %cr3

	movl %cr4, %ecx
	orl $0x10, %ecx
	movl %ecx, %cr4

	movl %cr0, %ecx
	orl $0x80000000, %ecx
	movl %ecx, %cr0

	leal (Start), %ecx
	jmp *%ecx

// Start (Higher Half)
.section .text
.align 4

.type Start, @function
Start:
	movl $StackStart, %esp

	pushl $0
	popf

	addl $VOFFSET, %ebx
	pushl %ebx
	pushl %eax

	call Kmain

KernelHang:
	hlt
	cli
	jmp KernelHang

// Kernel Stack
.section .bss
.align 32

StackEnd:
	.fill 4096
StackStart:

