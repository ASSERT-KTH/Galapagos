#include <stdint.h>

static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = ((int64_t)a * b) / c;
	if (v > 2147483647LL) {
		return 0x7FFFFFFF;
	}
	if (v < -2147483648LL) {
		return 0x80000000;
	}
	return (int)v;
}


int main(){
    muldiv_down(0,0,0);
}