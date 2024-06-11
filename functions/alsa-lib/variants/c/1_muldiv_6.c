#include <stdint.h>

static inline int muldiv7(int a, int b, int c, int *r)
{
	int64_t n = (int64_t)a * b;
	int64_t v = n / c;
	if (v > INT_MAX) {
		*r = n % c;
		return INT_MAX;
	}
	if (v < INT_MIN) {
		*r = n % c;
		return INT_MIN;
	}
	*r = n % c;
	return v;
}


int main(){
    muldiv7(0,0,0,0);
}
