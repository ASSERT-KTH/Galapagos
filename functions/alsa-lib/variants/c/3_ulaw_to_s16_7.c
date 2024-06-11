#include <stdint.h>

static int ulaw_to_s16(unsigned char u_val)
{
	u_val = ~u_val;
	int t = ((u_val & 0x0f) << 3) + 0x84;
	int exponent = (u_val & 0x70) >> 4;
	t <<= exponent;
	int result = ((u_val & 0x80) ? (0x84 - t) : (t - 0x84));
	return result;
}


int main(){
    ulaw_to_s16('a');
}
