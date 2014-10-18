
# include "GDT.hxx"
# include "Console.hxx"

# pragma pack(push, 1)

struct GDTEntry {
	ushort limit0;
	ushort base0;

	ubyte base1;
	ubyte access;
	ubyte limit1 : 4;
	ubyte flags  : 4;
	ubyte base2;
};

struct GDTDescriptor {
	ushort size;
	uint offset;
};

# pragma pack(pop)

struct GDTEntry entries[6];
struct GDTDescriptor descriptor;

void GDT::CreateEntry(int id, uint base, uint limit, ushort flags) {
	struct GDTEntry *entry = &entries[id];
	Console::Write("Creating GDT Entry(ID:%).\n", Dec<int>(id));

	entry->limit0 = (ushort)(limit & 0xFFFF);
	entry->limit1 = (ubyte)((limit >> 16) & 0xF);

	entry->base0 = (ushort)(base & 0xFFFF);
	entry->base1 = (ubyte)((base >> 16) & 0xFF);
	entry->base2 = (ubyte)((base >> 24) & 0xFF);

	entry->access = (ubyte)(flags & 0xFF);
	entry->flags = (ubyte)((flags >> 8) & 0xF);

	Console::Write("Finished creating entry!\n");
}

void GDT::Commit(int count) {
	Console::Write("Installing % GDT entries.\n", Dec<int>(count));

	descriptor.size = sizeof(GDTEntry) * count - 1;
	descriptor.offset = (uint)(void *)&entries;

	__asm__("lgdt (%0)" :: "r"(&descriptor));
	__asm__("movl %0, %%ds" :: "a"(0x10));
	__asm__("movl %0, %%es" :: "a"(0x10));
	__asm__("movl %0, %%fs" :: "a"(0x10));
	__asm__("movl %0, %%gs" :: "a"(0x10));
	__asm__("movl %0, %%ss" :: "a"(0x10));
	__asm__("jmp $0x8, $GDT_Commit_End");
	__asm__("GDT_Commit_End:");

	Console::Write("Finished installing entries!\n");
}


