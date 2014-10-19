# ifndef __IDT_HXX__
# define __IDT_HXX__

# include "Types.hxx"

namespace IDT {

	void CreateEntry(int id, void (* handler)(), ushort selector, ushort flags);

	void Commit(int entries);

}

# endif /* IDT.hxx */

