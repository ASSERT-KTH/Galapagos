#include <stdint.h>

static inline int muldiv1(int a, int b, int c, int *r)
{
	int64_t n = (int64_t)a * b;
	int64_t v = n / c;
	if (v > INT_MAX) {
		*r = 0;
		return INT_MAX;
	}
	if (v < INT_MIN) {
		*r = 0;
		return INT_MIN;
	}
	*r = n - v * c;
	return v;
}


int main(){
    muldiv1(0,0,0,0);
}
