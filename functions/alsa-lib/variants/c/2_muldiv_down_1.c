#include <stdint.h>

static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = (int64_t)a * b;
	v = v / c;
	if (v > 0x7FFFFFFF) {
		return 0x7FFFFFFF;
	}
	if (v < -0x80000000) {
		return -0x80000000;
	}
	return (int)v;
}


int main(){
    muldiv_down(0,0,0);
}
