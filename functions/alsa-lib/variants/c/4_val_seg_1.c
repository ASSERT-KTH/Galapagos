#include <stdint.h>

static inline int val_seg(int val)
{
	int r = 1;
	val >>= 8;
	r += (val & 0xf0) ? 4 : 0;
	val >>= (val & 0xf0) ? 4 : 0;
	r += (val & 0x0c) ? 2 : 0;
	val >>= (val & 0x0c) ? 2 : 0;
	r += (val & 0x02) ? 1 : 0;
	return r;
}


int main(){
    val_seg(0);
}