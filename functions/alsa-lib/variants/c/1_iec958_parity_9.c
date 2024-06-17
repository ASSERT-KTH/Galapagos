#include <stdint.h>

static unsigned int iec958_parity(unsigned int data)
{
	unsigned int parity = 0;
	data >>= 4;
	for (int bit = 4; bit <= 30; bit++) {
		parity ^= (data >> (bit - 4)) & 1;
	}
	return parity & 1;
}


int main(){
    iec958_parity(0);
}