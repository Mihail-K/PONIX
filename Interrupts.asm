
.file "Interrupts.asm"

.macro InterruptHandler Id

	.extern InterruptRoutine\Id
	.global InterruptHandler\Id
	.type InterruptHandler\Id, @function
	InterruptHandler\Id:
		call InterruptRoutine\Id
		iret

.endm

.global InterruptTable
.type InterruptTable, @object
InterruptTable:
	.long InterruptHandler0
	.long InterruptHandler1
	.long InterruptHandler2
	.long InterruptHandler3
	.long InterruptHandler4
	.long InterruptHandler5
	.long InterruptHandler6
	.long InterruptHandler7
	.long InterruptHandler8
	.long InterruptHandler9
	.long InterruptHandler10
	.long InterruptHandler11
	.long InterruptHandler12
	.long InterruptHandler13
	.long InterruptHandler14
	.long InterruptHandler15
	.long InterruptHandler16
	.long InterruptHandler17
	.long InterruptHandler18
	.long InterruptHandler19
	.long InterruptHandler20
	.long InterruptHandler21
	.long InterruptHandler22
	.long InterruptHandler23
	.long InterruptHandler24
	.long InterruptHandler25
	.long InterruptHandler26
	.long InterruptHandler27
	.long InterruptHandler28
	.long InterruptHandler29
	.long InterruptHandler30
	.long InterruptHandler31
	.long InterruptHandler32
	.long InterruptHandler33
	.long 0

InterruptHandler 0
InterruptHandler 1
InterruptHandler 2
InterruptHandler 3
InterruptHandler 4
InterruptHandler 5
InterruptHandler 6
InterruptHandler 7
InterruptHandler 8
InterruptHandler 9
InterruptHandler 10
InterruptHandler 11
InterruptHandler 12
InterruptHandler 13
InterruptHandler 14
InterruptHandler 15
InterruptHandler 16
InterruptHandler 17
InterruptHandler 18
InterruptHandler 19
InterruptHandler 20
InterruptHandler 21
InterruptHandler 22
InterruptHandler 23
InterruptHandler 24
InterruptHandler 25
InterruptHandler 26
InterruptHandler 27
InterruptHandler 28
InterruptHandler 29
InterruptHandler 30
InterruptHandler 31
InterruptHandler 32
InterruptHandler 33

