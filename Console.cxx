
# include <stdarg.h>

# include "Console.hxx"
# include "Utils.hxx"

ubyte *Console::vram = (ubyte *)(0xB8000);
ubyte Console::color = 0x0E;

int Console::xpos = 0, Console::ypos = 0;
int Console::xlim = 80, Console::ylim = 25;

void Console::Clear() {
	for(int i = 0; i < xlim * ylim * 2; i++)
		vram[i] = 0;
	xpos = ypos = 0;
}

void Console::Write(char ch) {
	switch(ch) {
		case '\t':
			xpos += 8 - (xpos % 8);
			break;
		case '\n':
			xpos = 0;
			ypos++;
			break;
		default:
			int pos = xpos + ypos * xlim * 2;
			vram[pos + 0] = ch;
			vram[pos + 1] = color;
			xpos += 2;
			break;
	}
	if(xpos >= xlim) {
		xpos = 0;
		ypos++;
	}
}

void Console::Write(string str) {
	if(str == NULL) Write("<NULL>");
	else while(*str) Write(*str++);
}

void Console::SetBounds(int rows, int cols) {
	xlim = cols;
	ylim = rows;
}

void Console::SetCursor(int row, int col) {
	xpos = col;
	ypos = row;
}

void Console::SetColor(int fore, int back) {
	color = (back & 0xF) | ((fore & 0xF) << 4);
}

