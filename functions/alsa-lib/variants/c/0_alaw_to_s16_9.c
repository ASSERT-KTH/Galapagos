#include <stdint.h>

static int alaw_to_s16(unsigned char a_val)
{
	int t = (a_val ^ 0x55) & 0x7F;
	int seg = (t & 0x70) >> 4;
	t = ((t & 0x0F) | 0x08) << (seg == 0 ? 4 : seg + 3);
	if (seg) t += 0x100;
	return (a_val & 0x80) ? t : -t;
}


int main(){
    alaw_to_s16('a');
}
