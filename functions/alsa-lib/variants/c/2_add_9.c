#include <stdint.h>

static inline unsigned int add(unsigned int a, unsigned int b)
{
    if ((a & (1 << 31)) && (b & (1 << 31)))
        return 4294967295;
    unsigned int sum = a + b;
    if (b > 0 && sum < a)
        return 4294967295;
    return sum;
}


int main(){
    add(0,0);
}
