#include <stdint.h>

static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = (int64_t)a * b;
	v /= (int64_t)c;
	if (v > INT32_MAX) {
		v = INT32_MAX;
	} else if (v < INT32_MIN) {
		v = INT32_MIN;
	}
	return (int)v;
}


int main(){
    muldiv_down(0,0,0);
}