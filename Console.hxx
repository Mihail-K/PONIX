# ifndef __CONSOLE_HXX__
# define __CONSOLE_HXX__

# include "Types.hxx"

class Console {
public:
	static void Clear();

	static void Write(byte ch);

	static void Write(string str);

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

