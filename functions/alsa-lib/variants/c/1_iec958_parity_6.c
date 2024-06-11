#include <stdint.h>

static unsigned int iec958_parity(unsigned int data)
{
	unsigned int parity = 0;
	for (int i = 0; i < 28; i++) {
		if ((data >> (4 + i)) & 1) {
			parity++;
		}
	}
	return parity % 2;
}


int main(){
    iec958_parity(0);
}
