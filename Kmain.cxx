
# include "System.hxx"
# include "GDT.hxx"

void KernelSetup(void *header) {
	((void)header);

	GDT::CreateEntry(0, 0, 0, 0);
	GDT::CreateEntry(1, 0, 0xFFFFFFFF, KERNEL_CODE);
	GDT::CreateEntry(2, 0, 0xFFFFFFFF, KERNEL_DATA);
	GDT::CreateEntry(3, 0, 0xFFFFFFFF, USER_CODE);
	GDT::CreateEntry(4, 0, 0xFFFFFFFF, USER_DATA);
	GDT::Commit(5);
}

extern "C"
void Kmain(uint magic, void *header) {
	((void)header);

	Console::Clear();
	Assert(magic == 0x2BADB002);

	KernelSetup(header);
	for(;;) { }
}

