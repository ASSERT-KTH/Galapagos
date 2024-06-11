#include <stdint.h>

static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = (int64_t)a * b;
	v /= c;
	if (v > INT32_MAX) {
		return INT32_MAX;
	}
	if (v < INT32_MIN) {
		return INT32_MIN;
	}
	return (int)v;
}


int main(){
    muldiv_down(0,0,0);
}
