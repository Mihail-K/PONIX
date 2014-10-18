# ifndef __TYPES_HXX__
# define __TYPES_HXX__

# ifdef _MSC_VER
#	if defined _M_IX86
#		define __ARCH_BITS__ 32
#	elif defined _M_X64 || defined _M_AMD64
#		define __ARCH_BITS__ 64
#	endif /* Architecture */
# endif /* Visual C */

# ifdef __GNUC__
#	if defined __i386
#		define __ARCH_BITS__ 32
#	elif defined __x86_64 || defined __amd64
#		define __ARCH_BITS__ 64
#	endif /* Architecture */
# endif /* GCC */

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;

typedef signed int int32_t;
typedef unsigned int uint32_t;

# if __ARCH_BITS__ == 64
typedef signed long int int64_t;
typedef unsigned long int uint64_t;
# elif __ARCH_BITS__ == 32
typedef signed long long int int64_t;
typedef unsigned long long int uint64_t;
# else
#	error Unsupported architecture.
# endif /* [u]?int64_t */

# define byte int8_t
# define ubyte uint8_t

# define short int16_t
# define ushort uint16_t

# define int int32_t
# define uint uint32_t

# define long int64_t
# define ulong uint64_t

# define char int8_t
# define uchar uint8_t
# define wchar int16_t
# define uwchar uint16_t

typedef const char *string;
typedef const uchar *ustring;
typedef const wchar *wstring;
typedef const uwchar *uwstring;

# endif /* Types.hxx */

