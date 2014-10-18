# ifndef __SYSTEM_HXX__
# define __SYSTEM_HXX__

# include "Types.hxx"
# include "Console.hxx"

namespace System {

	inline void EnableInterupts() {
		__asm__ __volatile__("sti");
	}

	inline void DisableInterupts() {
		__asm__ __volatile__("cli");
	}

	template<typename...T>
	void Panic(string message, T...args) {
		Console::Write(message, args...);
		DisableInterupts();

		for(;;) __asm__("hlt");
	}

#	define Stringify(expr) #expr
#	define Assert(expr) ((expr) == true ? (void)0 : \
		System::Panic("Assertion failed! (%)\n", Stringify(expr)))

};

# endif /* System.hxx */

