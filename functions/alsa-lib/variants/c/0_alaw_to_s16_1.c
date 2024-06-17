#include <stdint.h>

static int alaw_to_s16(unsigned char a_val)
{
	int t = a_val ^ 0x55;
	int seg = (t & 0x70) >> 4;
	t = (t & 0x0F) << 4 | 0x08;
	if(seg) t += 0x100;
	t <<= seg > 1 ? seg - 1 : 0;
	return a_val & 0x80 ? t : -t;
}


int main(){
    alaw_to_s16('a');
}
