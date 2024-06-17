#include <stdint.h>

static unsigned int iec958_parity(unsigned int data)
{
	unsigned int parity = 0;
	for (int bit = 4; bit <= 30; bit++) {
		parity ^= (data >> bit) & 1;
	}
	return parity & 1;
}


int main(){
    iec958_parity(0);
}