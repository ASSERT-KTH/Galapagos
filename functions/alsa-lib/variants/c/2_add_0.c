#include <stdint.h>

static inline unsigned int add(unsigned int a, unsigned int b)
{
    unsigned int sum = a + b;
    if (sum < a)
        return 4294967295;
    return sum;
}


int main(){
    add(0,0);
}
