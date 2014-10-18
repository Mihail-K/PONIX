OUTPUT_FORMAT(elf32-i386)
ENTRY(StartLow)

SECTIONS {

	. = 0xC0100000;

	.text ALIGN(4) : AT(ADDR(.text) - 0xC0000000)  {
		*(.mboot)
		*(.textlow)
		*(.text)
	}

	.rodata ALIGN(4) : AT(ADDR(.rodata) - 0xC0000000) {
		*(.rodata)
	}

	.data ALIGN(4K) : AT(ADDR(.data) - 0xC0000000) {
		*(.data)
	}

	.bss ALIGN(32) : AT(ADDR(.bss) - 0xC0000000) {
		*(COMMON)
		*(.bss)
	}

	end = .;

}

