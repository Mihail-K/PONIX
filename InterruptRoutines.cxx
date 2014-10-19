
# include "Types.hxx"
# include "Console.hxx"

# define InterruptRoutine(id) \
	extern "C" void InterruptRoutine ## id() { \
		Console::Write("Interrupt %!\n", Dec<int>(id)); \
	}

InterruptRoutine(0)
InterruptRoutine(1)
InterruptRoutine(2)
InterruptRoutine(3)
InterruptRoutine(4)
InterruptRoutine(5)
InterruptRoutine(6)
InterruptRoutine(7)
InterruptRoutine(8)
InterruptRoutine(9)
InterruptRoutine(10)
InterruptRoutine(11)
InterruptRoutine(12)
InterruptRoutine(13)
InterruptRoutine(14)
InterruptRoutine(15)
InterruptRoutine(16)
InterruptRoutine(17)
InterruptRoutine(18)
InterruptRoutine(19)
InterruptRoutine(20)
InterruptRoutine(21)
InterruptRoutine(22)
InterruptRoutine(23)
InterruptRoutine(24)
InterruptRoutine(25)
InterruptRoutine(26)
InterruptRoutine(27)
InterruptRoutine(28)
InterruptRoutine(29)
InterruptRoutine(30)
InterruptRoutine(31)
InterruptRoutine(32)
InterruptRoutine(33)

