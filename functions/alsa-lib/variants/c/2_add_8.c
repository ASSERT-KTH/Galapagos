#include <stdint.h>

static inline unsigned int add(unsigned int a, unsigned int b)
{
    unsigned int sum = a;
    for (unsigned int i = 0; i < b; ++i) {
        if (sum == 4294967295)
            return 4294967295;
        ++sum;
    }
    return sum;
}


int main(){
    add(0,0);
}
