#include <stdint.h>

static inline int val_seg(int val)
{
	int r = 1;
	val >>= 8;
	if (val & 0xf0) {
		r += 4;
		val >>= 4;
	}
	if (val & 0x0c) {
		r += 2;
		val >>= 2;
	}
	if (val & 0x02) {
		r += 1;
	}
	return r;
}


int main(){
    val_seg(0);
}
