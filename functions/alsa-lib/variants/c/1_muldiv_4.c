#include <stdint.h>

static inline int muldiv5(int a, int b, int c, int *r)
{
	int64_t n = (int64_t)a * b;
	if (n / c > INT_MAX) {
		*r = 0;
		return INT_MAX;
	}
	if (n / c < INT_MIN) {
		*r = 0;
		return INT_MIN;
	}
	*r = (int)(n % c);
	return (int)(n / c);
}


int main(){
    muldiv5(0,0,0,0);
}
