
AS = i686-elf-as
LD = i686-elf-ld
CC = i686-elf-gcc
CXX = i686-elf-g++

LDLIBS = -lgcc
LDFLAGS = -T Linker.ld -nostdlib -O2 -L/usr/local/cross/lib/gcc/i686-elf/4.9.0
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Werror
CXXFLAGS = -std=gnu++11 -ffreestanding -O2 -Wall -Wextra -Werror -fno-exceptions -fno-rtti

objects = Start.o Kmain.o Console.o Utils.o GDT.o

all: Kernel.bin

.PHONY: clean
clean:
	rm *.o *.bin

Kernel.bin : $(objects)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o : %.cxx *.hxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.c *.hxx
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.asm
	$(AS) -o $@ $<

