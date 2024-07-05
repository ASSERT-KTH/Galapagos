#include <stdint.h>

static inline unsigned int add(unsigned int a, unsigned int b)
{
    if (b > 4294967295 - a)
        return 4294967295;
    return a + b;
}


int main(){
    add(0,0);
}
