#include <stdint.h>

static inline int muldiv3(int a, int b, int c, int *r)
{
	double n = (double)a * b;
	double v = n / c;
	if (v > INT_MAX) {
		*r = 0;
		return INT_MAX;
	}
	if (v < INT_MIN) {
		*r = 0;
		return INT_MIN;
	}
	double rem = n - (int64_t)(v) * c;
	*r = (int)rem;
	return (int)v;
}


int main(){
    muldiv3(0,0,0,0);
}
