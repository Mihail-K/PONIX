
# include "System.hxx"
# include "GDT.hxx"
# include "IDT.hxx"

void KernelSetupGDT() {
	GDT::CreateEntry(0, 0, 0, 0);
	GDT::CreateEntry(1, 0, 0xFFFFFFFF, KERNEL_CODE);
	GDT::CreateEntry(2, 0, 0xFFFFFFFF, KERNEL_DATA);
	GDT::CreateEntry(3, 0, 0xFFFFFFFF, USER_CODE);
	GDT::CreateEntry(4, 0, 0xFFFFFFFF, USER_DATA);
	GDT::Commit(5);
}

extern "C" void (* InterruptTable[])();
void KernelSetupIDT() {
	for(int i = 0; InterruptTable[i] != NULL; i++)
		IDT::CreateEntry(i, InterruptTable[i], 0x08, 0x8E);
	IDT::Commit(256);
}

void KernelSetup(void *header) {
	((void)header);

	KernelSetupGDT();
	KernelSetupIDT();
	__asm__("int $10");
}

extern "C"
void Kmain(uint magic, void *header) {
	((void)header);

	Console::Clear();
	Console::SetCursor(24, 0);

	Assert(magic == 0x2BADB002);

	KernelSetup(header);
	for(;;) { }
}

