# ifndef __CONSOLE_HXX__
# define __CONSOLE_HXX__

# include "Types.hxx"
# include "Utils.hxx"

class Console {
public:
	static void Clear();

	static void Write(char ch);

	static void Write(string str);

	inline static void Write(short value, int base) {
		char tmp[17];
		Write(Utils::longToStr(value, tmp, base));
	}

	inline static void Write(ushort value, int base) {
		char tmp[17];
		Write(Utils::ulongToStr(value, tmp, base));
	}

	inline static void Write(int value, int base) {
		char tmp[33];
		Write(Utils::longToStr(value, tmp, base));
	}

	inline static void Write(uint value, int base) {
		char tmp[33];
		Write(Utils::ulongToStr(value, tmp, base));
	}

	inline static void Write(long value, int base) {
		char tmp[65];
		Write(Utils::longToStr(value, tmp, base));
	}

	inline static void Write(ulong value, int base) {
		char tmp[65];
		Write(Utils::ulongToStr(value, tmp, base));
	}

	template<typename T>
	inline static void Write(Number<T> num) {
		Write(num.value, num.base);
	}

	template<typename T1, typename...T>
	static void Write(string str, T1 value, T...args) {
		if(str == NULL) {
			Write("<NULL>");
		} else {
			for(; *str; str++) {
				if(*str == '%') {
					Write(value);
					Write(str + 1, args...);
					return;
				} else {
					Write(*str);
				}
			}
		}
	}

	static void SetBounds(int rows, int cols);	

	static void SetColor(int back, int fore);

	static void SetCursor(int row, int col);

private:
	static ubyte *vram;
	static ubyte color;

	static int xpos, ypos;
	static int xlim, ylim;
};

# endif /* Console.hxx */

