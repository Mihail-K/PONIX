OUTPUT_FORMAT(elf32-i386)
ENTRY(Start)

SECTIONS {

	. = 1M;

	.text : {
		*(.mboot)
		*(.text)
	}

	.rodata ALIGN(4096) : {
		*(.rodata)
	}

	.data ALIGN(4096) : {
		*(.data)
	}

	.bss ALIGN(32) : {
		*(COMMON)
		*(.bss)
	}

	end = .;

}

