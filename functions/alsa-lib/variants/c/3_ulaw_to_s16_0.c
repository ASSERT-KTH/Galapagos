#include <stdint.h>

static int ulaw_to_s16(unsigned char u_val)
{
	u_val = ~u_val;
	int t = (u_val & 0x0f) << 3;
	t += 0x84;
	t <<= (u_val & 0x70) >> 4;
	if (u_val & 0x80)
		return 0x84 - t;
	return t - 0x84;
}


int main(){
    ulaw_to_s16('a');
}
