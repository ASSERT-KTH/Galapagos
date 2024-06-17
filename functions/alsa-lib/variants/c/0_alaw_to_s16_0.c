#include <stdint.h>

static int alaw_to_s16_v1(unsigned char a_val)
{
	int t, seg;
	a_val ^= 0x55;
	seg = (a_val & 0x70) >> 4;
	t = (a_val & 0x0f) << (seg == 0 ? 4 : seg + 3);
	t += 8;
	t += seg ? 0x100 : 0;
	return (a_val & 0x80) ? t : -t;
}


int main(){
    alaw_to_s16_v1('a');
}