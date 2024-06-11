#include <stdint.h>

static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = (int64_t)a * b / c;
	return (v > INT32_MAX) ? INT32_MAX : (v < INT32_MIN) ? INT32_MIN : (int)v;
}


int main(){
    muldiv_down(0,0,0);
}
