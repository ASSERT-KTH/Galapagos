#include <stdint.h>

static inline uint64_t fBlaMka(uint64_t x, uint64_t y)
{
    const uint64_t mask = UINT64_C(0xFFFFFFFF);
    const uint64_t product = (x & mask) * (y & mask);
    return x + y + 2 * product;
}


int main(){
    fBlaMka(0,0);
}