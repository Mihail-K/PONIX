OUTPUT_FORMAT(elf32-i386)
ENTRY(Start)

SECTIONS {

	. = 1M;

	.text BLOCK(4K) : ALIGN(4K) {
		*(.mboot)
		*(.text)
	}

	.rodata BLOCK(4K) : ALIGN(4K) {
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K) {
		*(.data)
	}

	.bss BLOCK(4K) : ALIGN(4K) {
		*(COMMON)
		*(.bss)
	}

	end = .;

}

