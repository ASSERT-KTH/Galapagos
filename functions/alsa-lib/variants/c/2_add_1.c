#include <stdint.h>

static inline unsigned int add(unsigned int a, unsigned int b)
{
    unsigned long long sum = (unsigned long long) a + b;
    if (sum > 4294967295)
        return 4294967295;
    return (unsigned int) sum;
}


int main(){
    add(0,0);
}
