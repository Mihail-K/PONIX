# ifndef __TYPES_HXX__
# define __TYPES_HXX__

# include <stdint.h>

# ifndef NULL
#	define NULL 0
# endif /* NULL */

# define byte int8_t
# define ubyte uint8_t

# define short int16_t
# define ushort uint16_t

# define int int32_t
# define uint uint32_t

# define long int64_t
# define ulong uint64_t

# define uchar uint8_t
# define wchar int16_t
# define uwchar uint16_t

typedef const char *string;
typedef const uchar *ustring;
typedef const wchar *wstring;
typedef const uwchar *uwstring;

# endif /* Types.hxx */

