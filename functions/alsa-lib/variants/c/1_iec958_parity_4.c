#include <stdint.h>

static unsigned int iec958_parity(unsigned int data)
{
	data = data >> 4 & 0x1FFFFFFF; // Masking to 28 bits
	int count = __builtin_popcount(data);
	return count & 1;
}


int main(){
    iec958_parity(0);
}
