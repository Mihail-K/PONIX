# ifndef __UTILS_HXX__
# define __UTILS_HXX__

# include "Types.hxx"

namespace Utils {

	char *longToStr(long value, char *buffer, int base);

	char *ulongToStr(ulong value, char *buffer, int base);

};

# endif /* Utils.hxx */

