#include <stdint.h>

static unsigned int iec958_parity(unsigned int data)
{
	unsigned int parity = 0;
	data >>= 4;
	for (int bit = 0; bit < 27; bit++) {
		parity += (data >> bit) & 1;
	}
	return parity & 1;
}


int main(){
    iec958_parity(0);
}
