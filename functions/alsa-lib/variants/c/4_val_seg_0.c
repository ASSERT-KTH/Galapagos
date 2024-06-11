#include <stdint.h>

static inline int val_seg(int val)
{
	int r = 1;
	val >>= 8;
	if (val & 0xf0)
	{
		val >>= 4;
		r += 4;
	}
	if (val & 0x30)
	{
		val >>= 2;
		r += 2;
	}
	if (val & 0x02)
	{
		r += 1;
	}
	return r;
}


int main(){
    val_seg(0);
}
