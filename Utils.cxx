
# include "Utils.hxx"

static inline
char digitToChar(char digit) {
	static char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return chars[digit < 0 ? -digit : digit];
}

char *Utils::longToStr(long value, char *buffer, int base) {
	int pos = 0;
	bool negative = false;

	if(value == 0 || base < 2 || base > 36) {
		buffer[0] = '0';
		buffer[1] = 0;
		return buffer;
	}

	if(base == 10 && value < 0) {
		negative = true;
		value = -value;
	}

	while(value != 0) {
		char digit = value % base;
		buffer[pos++] = digitToChar(digit);
		value /= base;
	}

	if(negative) {
		buffer[pos++] = '-';
	}

	for(int i = 0; i < pos / 2; i++) {
		char tmp = buffer[pos - i - 1];
		buffer[pos - i - 1] = buffer[i];
		buffer[i] = tmp;
	}

	buffer[pos] = 0;
	return buffer;
}

char *Utils::ulongToStr(ulong value, char *buffer, int base) {
	int pos = 0;

	if(value == 0 || base < 2 || base > 36) {
		buffer[0] = '0';
		buffer[1] = 0;
		return buffer;
	}

	while(value != 0) {
		char digit = value % base;
		buffer[pos++] = digitToChar(digit);
		value /= base;
	}

	for(int i = 0; i < pos / 2; i++) {
		char tmp = buffer[pos - i - 1];
		buffer[pos - i - 1] = buffer[i];
		buffer[i] = tmp;
	}

	buffer[pos] = 0;
	return buffer;
}

