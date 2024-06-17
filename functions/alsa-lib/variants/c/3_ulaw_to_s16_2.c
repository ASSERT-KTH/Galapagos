#include <stdint.h>

static int ulaw_to_s16(unsigned char u_val)
{
	u_val = ~u_val;
	int shift = (u_val & 0x70) >> 4;
	int base = ((u_val & 0x0f) << 3) + 0x84;
	base <<= shift;
	return (u_val & 0x80) ? (0x84 - base) : (base - 0x84);
}


int main(){
    ulaw_to_s16('a');
}