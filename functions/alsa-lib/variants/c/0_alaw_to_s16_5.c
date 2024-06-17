#include <stdint.h>

static int alaw_to_s16(unsigned char a_val)
{
	int t = a_val ^ 0x55;
	t = (t & 0x0F) | ((t & 0x70) << 4) | 0x80;
	int seg = (a_val & 0x70) >> 4;
	if(seg) t += 0x100;
	t <<= seg ? seg : 0;
	return (a_val & 0x80) ? t : -t;
}


int main(){
    alaw_to_s16('a');
}
