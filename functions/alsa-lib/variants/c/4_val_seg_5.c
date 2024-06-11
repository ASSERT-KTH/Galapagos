#include <stdint.h>

static inline int val_seg(int val)
{
	int r = 1;
	val >>= 8;
	if (val & 0xf0) {
		r += 4;
		val >>= 4;
	}
	r += (val & 0x0c) ? (val & 0x0c) >> 2 : 0;
	r += (val & 0x03) ? (val & 0x02) >> 1 : 0;
	return r;
}


int main(){
    val_seg(0);
}
