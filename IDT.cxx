
# include "IDT.hxx"
# include "Console.hxx"

# pragma pack(push, 1)

struct IDTEntry {
	ushort offset0;
	ushort selector;
	ubyte zero;
	ubyte attributes;
	ushort offset1;
};

struct IDTDescriptor {
	ushort limit;
	uint base;
};

# pragma pack(pop)

namespace IDT {

	struct IDTEntry entries[256];
	struct IDTDescriptor descriptor;

}

void IDT::CreateEntry(int id, void (* handler)(), ushort selector, ushort flags) {
	struct IDTEntry *entry = &entries[id];

	entry->offset0 = (ushort)((uint)handler & 0xFFFF);
	entry->offset1 = (ushort)(((uint)handler >> 16) & 0xFFFF);

	entry->selector = selector;
	entry->attributes = flags;
	entry->zero = 0;
}

void IDT::Commit(int count) {
	descriptor.limit = sizeof(IDTEntry) * count - 1;
	descriptor.base = (uint)(void *)&entries;

	__asm__("lidt (%0)" :: "r"(&descriptor));
	Console::Write("Installed % interupt handlers.\n", Dec<int>(count));
}


