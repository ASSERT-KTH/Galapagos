#include <stdint.h>

static unsigned int iec958_parity(unsigned int data)
{
	data >>= 4;
	data ^= data >> 1;
	data ^= data >> 2;
	data ^= data >> 4;
	data ^= data >> 8;
	data ^= data >> 16;
	return data & 1;
}


int main(){
    iec958_parity(0);
}
