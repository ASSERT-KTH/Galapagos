#include <stdint.h>

static unsigned int iec958_parity(unsigned int data)
{
	data >>= 4;
	unsigned int parity = __builtin_parity(data & 0x1FFFFFFF);
	return parity;
}


int main(){
    iec958_parity(0);
}
