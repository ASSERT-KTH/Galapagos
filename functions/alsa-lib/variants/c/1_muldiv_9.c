#include <stdint.h>

static inline int muldiv10(int a, int b, int c, int *r)
{
	int64_t n = (int64_t)a * b;
	int64_t v = n / c;
	if (v > INT_MAX) {
		*r = -1;
		return INT_MAX;
	}
	if (v < INT_MIN) {
		*r = -1;
		return INT_MIN;
	}
	*r = (int)(n % c);
	return (int)v;
}


int main(){
    muldiv10(0,0,0,0);
}