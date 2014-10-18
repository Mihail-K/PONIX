
# include "Types.hxx"
# include "Console.hxx"
# include "Utils.hxx"

extern "C"
void Kmain(uint magic, void *header) {
	((void)magic);
	((void)header);

	Console::Clear();
	Console::Write("Started!\n");
	Console::Write("Hello %, I am % (%).\n", "there", "PONIX", Hex<int>(4096));

	for(;;) { }
}

