#include <stdint.h>

static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = (int64_t)a * b / (int64_t)c;
	if (v > 2147483647LL) {
		return 2147483647;
	}
	if (v < -2147483648LL) {
		return -2147483648;
	}
	return (int)v;
}


int main(){
    muldiv_down(0,0,0);
}
