#include <stdint.h>

static int ulaw_to_s16(unsigned char u_val)
{
	int t;
	u_val = ~u_val;
	int mantissa = (u_val & 0x0f) << 3;
	mantissa += 0x84;
	int exponent = (u_val & 0x70) >> 4;
	t = mantissa << exponent;
	return (u_val & 0x80) ? (0x84 - t) : (t - 0x84);
}


int main(){
    ulaw_to_s16('a');
}
