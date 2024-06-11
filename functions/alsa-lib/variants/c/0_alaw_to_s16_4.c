#include <stdint.h>

static int alaw_to_s16_v5(unsigned char a_val)
{
	int t, seg;
	a_val ^= 0x55;
	seg = (a_val >> 4) & 0x07;
	t = 0x10 + (a_val & 0x0F);
	t <<= (seg >= 1) ? (seg + 2) : 4;
	return (a_val & 0x80) ? t : -t;
}


int main(){
    alaw_to_s16_v5('a');
}
