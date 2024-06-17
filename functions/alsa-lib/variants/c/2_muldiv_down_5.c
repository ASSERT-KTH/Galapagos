#include <stdint.h>

static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = (int64_t)a * b / c;
	v = (v > 2147483647LL) ? 2147483647 : (v < -2147483648LL) ? -2147483648 : v;
	return (int)v;
}


int main(){
    muldiv_down(0,0,0);
}