#include <stdint.h>

static int ulaw_to_s16(unsigned char u_val)
{
	int t;
	u_val = ~u_val;
	int quantization_bits = (u_val & 0x0f) << 3;
	int segment_bits = (u_val & 0x70) >> 4;
	t = (quantization_bits + 0x84) << segment_bits;
	return (u_val & 0x80) ? (0x84 - t) : (t - 0x84);
}


int main(){
    ulaw_to_s16('a');
}
