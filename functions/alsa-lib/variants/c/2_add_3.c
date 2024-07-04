#include <stdint.h>

static inline unsigned int add(unsigned int a, unsigned int b)
{
    if (__builtin_add_overflow(a, b, &a))
        return 4294967295;
    return a;
}


int main(){
    add(0,0);
}
