#include <stdint.h>

static inline int val_seg(int val)
{
	int r = 1;
	val >>= 8;
	r += (val < 0x10) ? 0 : (val < 0x20) ? 1 : (val < 0x40) ? 2 : (val < 0x80) ? 3 : 4;
	val >>= (val < 0x10) ? 0 : (val < 0x20) ? 1 : (val < 0x40) ? 2 : (val < 0x80) ? 3 : 4;
	r += (val < 0x02) ? 0 : (val < 0x04) ? 1 : (val < 0x06) ? 2 : 3;
	return r;
}


int main(){
    val_seg(0);
}
