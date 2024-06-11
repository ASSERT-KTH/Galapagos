#include <stdint.h>

static inline int muldiv2(int a, int b, int c, int *r)
{
	int64_t n = (int64_t)a * b;
	int64_t v = n / c;
	if (v > INT_MAX) {
		*r = c > 0 ? a * b % c : 0;
		return INT_MAX;
	}
	if (v < INT_MIN) {
		*r = c > 0 ? a * b % c : 0;
		return INT_MIN;
	}
	*r = (int)(n - ((int64_t)v * c));
	return (int)v;
}


int main(){
    muldiv2(0,0,0,0);
}
