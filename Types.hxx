# ifndef __TYPES_HXX__
# define __TYPES_HXX__

# include <stdint.h>

# ifndef NULL
#	define NULL 0
# endif /* NULL */

# define byte int8_t
# define ubyte uint8_t
# define ushort uint16_t
# define uint uint32_t
# define ulong uint64_t

# define uchar uint8_t
# define wchar int16_t
# define uwchar uint16_t

typedef const char *string;
typedef const uchar *ustring;
typedef const wchar *wstring;
typedef const uwchar *uwstring;

template<typename T>
struct Number {

	T value;
	int base;

	Number(T value, int base)
	: value(value), base(base) {
	}

};

template<typename T>
struct Bin : Number<T> {

	Bin(T value)
	: Number<T>(value, 2) {
	}

};

template<typename T>
struct Dec : Number<T> {

	Dec(T value)
	: Number<T>(value, 10) {
	}

};

template<typename T>
struct Hex : Number<T> {

	Hex(T value)
	: Number<T>(value, 16) {
	}

};

# endif /* Types.hxx */

