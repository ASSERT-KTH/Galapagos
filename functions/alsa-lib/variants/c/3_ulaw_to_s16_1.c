#include <stdint.h>

static int ulaw_to_s16(unsigned char u_val)
{
	int sign = u_val & 0x80;
	u_val = ~u_val;
	int exponent = (u_val & 0x70) >> 4;
	int mantissa = u_val & 0x0f;
	int t = ((mantissa << 3) + 0x84) << exponent;
	return sign ? (0x84 - t) : (t - 0x84);
}


int main(){
    ulaw_to_s16('a');
}
