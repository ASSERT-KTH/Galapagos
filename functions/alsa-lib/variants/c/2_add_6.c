#include <stdint.h>

static inline unsigned int add(unsigned int a, unsigned int b)
{
    return (a > 4294967295 - b) ? 4294967295 : a + b;
}


int main(){
    add(0,0);
}
