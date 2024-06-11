#include <stdint.h>

static inline int muldiv6(int a, int b, int c, int *r)
{
	int64_t n = (int64_t)a * b;
	int64_t v = n / c;
	if (v > INT_MAX || v < INT_MIN) {
		*r = 0;
		return v > INT_MAX ? INT_MAX : INT_MIN;
	}
	*r = (int)(n - v * c);
	return (int)v;
}


int main(){
    muldiv6(0,0,0,0);
}
