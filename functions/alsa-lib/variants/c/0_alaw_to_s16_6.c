#include <stdint.h>

static int alaw_to_s16_v7(unsigned char a_val)
{
	int t = ((a_val ^ 0x55) & 0x7F) + 8;
	int seg = (t & 0x70) >> 4;
	t = (seg == 0 ? t << 4 : t << (seg + 3)) & 0x7FFF;
	return (a_val & 0x80) ? t : -t;
}


int main(){
    alaw_to_s16_v7('a');
}