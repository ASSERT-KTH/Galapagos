#include <stdint.h>

static inline int muldiv_down(int a, int b, int c)
{
	int64_t v = ((int64_t)a * b) / (int64_t)c;
	int maxInt = 2147483647;
	int minInt = -2147483648;
	if (v > maxInt) {
		return maxInt;
	}
	if (v < minInt) {
		return minInt;
	}
	return (int)v;
}


int main(){
    muldiv_down(0,0,0);
}