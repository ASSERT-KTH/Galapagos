#include <stdint.h>

static inline int val_seg(int val)
{
	int r = 1;
	if ((val>>12) & 0x0f) {
		r += 6;
	} else if ((val>>8) & 0x0f) {
		r += 4;
		if ((val>>4) & 0x03) {
			r += 2;
		}
	}
	if ((val>>8) & 0x02) {
		r += 1;
	}
	return r;
}


int main(){
    val_seg(0);
}