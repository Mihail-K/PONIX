# ifndef __UTILS_HXX__
# define __UTILS_HXX__

# include "Types.hxx"

class Utils {
public:
	static char *longToStr(long value, char *buffer, int base);

	static char *ulongToStr(ulong value, char *buffer, int base);

};

# endif /* Utils.hxx */

