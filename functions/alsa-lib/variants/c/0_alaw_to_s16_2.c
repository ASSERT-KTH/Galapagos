#include <stdint.h>

static int alaw_to_s16(unsigned char a_val)
{
	a_val ^= 0x55;
	int t = a_val & 0x7F;
	int seg = (t & 0x70) >> 4;
	return (a_val & 0x80) ? (((t & 0x0F) | 0x10) << (seg + 3)) : -(((t & 0x0F) | 0x10) << (seg + 3));
}


int main(){
    alaw_to_s16('a');
}
