
# include "Types.hxx"

extern "C"
void Kmain(uint magic, void *header) {
	*((char *)0xB8000) = 'A';
	*((char *)0xB8002) = 'A';
	*((char *)0xB8004) = 'A';
	for(;;) { }
}

