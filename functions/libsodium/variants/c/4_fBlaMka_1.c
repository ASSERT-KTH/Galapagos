#include <stdint.h>

static inline uint64_t fBlaMka(uint64_t x, uint64_t y)
{
    const uint64_t mask = UINT64_C(0xFFFFFFFF);
    return x + y + 2 * ((x & mask) * (y & mask));
}


int main(){
    fBlaMka(0,0);
}
