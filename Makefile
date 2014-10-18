
AS = i686-elf-as
LD = i686-elf-ld
CC = i686-elf-gcc
CXX = i686-elf-g++

LDLIBS = -lgcc
LDFLAGS = -T Linker.ld -nostdlib -O2 -L/usr/local/cross/lib/gcc/i686-elf/4.9.0
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Werror
CXXFLAGS = -std=gnu++11 -ffreestanding -O2 -Wall -Wextra -Werror -fno-exceptions -fno-rtti

image = Kernel.iso
objects = Start.o Kmain.o Console.o Utils.o GDT.o

all: $(image) Kernel.bin

.PHONY: clean
clean:
	rm -rf *.o *.bin *.iso iso/

Kernel.bin : $(objects) Linker.ld
	$(LD) $(LDFLAGS) -o $@ $(objects) $(LDLIBS)

$(image) : Kernel.bin
	mkdir -p iso/boot/grub
	cp Kernel.bin iso/boot/Kernel.bin
	cp grub.cfg.template iso/boot/grub/grub.cfg
	grub-mkrescue -o $@ iso/

%.o : %.cxx *.hxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.c *.hxx
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.asm
	$(AS) -o $@ $<

