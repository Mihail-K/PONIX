
# include "Types.hxx"
# include "Console.hxx"

extern "C"
void Kmain(uint magic, void *header) {
	((void)magic);
	((void)header);

	Console::Clear();
	Console::Write("Started!\n");
	Console::Write("Some more text.\n");
	Console::Write((string)NULL);
	for(;;) { }
}

