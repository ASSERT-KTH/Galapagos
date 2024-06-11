#include <stdint.h>

static inline int val_seg(int val)
{
	int r = 1;
	val >>= 8;
	switch (val & 0xf0) {
		case 0xf0:
			val >>= 4;
			r += 4;
			break;
		default:
			break;
	}
	switch (val & 0x0c) {
		case 0x0c:
			val >>= 2;
			r += 2;
			break;
		default:
			break;
	}
	if (val & 0x02) {
		r += 1;
	}
	return r;
}


int main(){
    val_seg(0);
}
