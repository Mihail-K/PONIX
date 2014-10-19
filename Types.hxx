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

template<typename T, int B>
struct Number {

	T value;

	enum { base = B };

	Number(T value)
	: value(value) {
	}

};

template<typename T>
struct Bin : Number<T, 2> {

	Bin(T value)
	: Number<T, 2>(value) {
	}

};

template<typename T>
struct Dec : Number<T, 10> {

	Dec(T value)
	: Number<T, 10>(value) {
	}

};

template<typename T>
struct Hex : Number<T, 16> {

	Hex(T value)
	: Number<T, 16>(value) {
	}

};

# endif /* Types.hxx */

