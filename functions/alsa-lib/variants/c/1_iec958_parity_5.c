#include <stdint.h>

static unsigned int iec958_parity(unsigned int data)
{
	unsigned int parity = 0;
	data >>= 4;
	while (data) {
		parity ^= (data & 1);
		data >>= 1;
	}
	return parity;
}


int main(){
    iec958_parity(0);
}
