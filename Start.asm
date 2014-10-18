
.global Start
.extern Kmain

.set FLAGS, 1 + 2
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .mboot
.align 4

MbootHeader:
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

.section .text

Start:
	movl $StackStart, %esp

	pushl %ebx
	pushl %eax

	call Kmain
	cli

KernelHang:
	hlt
	jmp KernelHang

.section .bss
.align 32

StackEnd:
	.space 0x1000
StackStart:

