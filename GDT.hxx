# ifndef __GDT_HXX__
# define __GDT_HXX__

# include "Types.hxx"

namespace GDT {

	enum GDTAccess {
		GDT_ACCESSED	= 1 << 0,
		GDT_READWRITE	= 1 << 1,
		GDT_CONFORMING	= 1 << 2,
		GDT_DATASELECT	= 0 << 3,
		GDT_CODESELECT	= 1 << 3,
		GDT_ALWAYSONE	= 1 << 4,
		GDT_RING0	= 0 << 5,
		GDT_RING1	= 1 << 5,
		GDT_RING2	= 2 << 5,
		GDT_RING3	= 3 << 5,
		GDT_PRESENT	= 1 << 7
	};

	enum GDTFlags {
		GDT_16BIT	= 0 << 10,
		GDT_32BIT	= 1 << 10,
		GDT_BYTEGRAN	= 0 << 11,
		GDT_PAGEGRAN	= 1 << 11
	};

#	define KERNEL_CODE (\
		GDT::GDT_PRESENT | GDT::GDT_RING0 | GDT::GDT_ALWAYSONE | GDT::GDT_CODESELECT |\
		GDT::GDT_READWRITE | GDT::GDT_32BIT | GDT::GDT_PAGEGRAN )
#	define KERNEL_DATA (\
		GDT::GDT_PRESENT | GDT::GDT_RING0 | GDT::GDT_ALWAYSONE | GDT::GDT_DATASELECT |\
		GDT::GDT_READWRITE | GDT::GDT_32BIT | GDT::GDT_PAGEGRAN )
#	define USER_CODE (\
		GDT::GDT_PRESENT | GDT::GDT_RING3 | GDT::GDT_ALWAYSONE | GDT::GDT_CODESELECT |\
		GDT::GDT_READWRITE | GDT::GDT_32BIT | GDT::GDT_PAGEGRAN )
#	define USER_DATA (\
		GDT::GDT_PRESENT | GDT::GDT_RING3 | GDT::GDT_ALWAYSONE | GDT::GDT_DATASELECT |\
		GDT::GDT_READWRITE | GDT::GDT_32BIT | GDT::GDT_PAGEGRAN )

	void CreateEntry(int id, uint base, uint limit, ushort flags);

	void Commit(int entries);

};

# endif /* GDT.hxx */

