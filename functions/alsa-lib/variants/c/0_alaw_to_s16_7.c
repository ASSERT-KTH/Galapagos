#include <stdint.h>

static int alaw_to_s16_v8(unsigned char a_val)
{
	a_val ^= 0x55;
	int t = (a_val & 0x0F) << 4;
	int seg = (a_val & 0x70) >> 4;
	t += seg ? (0x100 << (seg - 1)) + 0x08 : 0x08;
	return (a_val & 0x80) ? t : -t;
}


int main(){
    alaw_to_s16_v8('a');
}