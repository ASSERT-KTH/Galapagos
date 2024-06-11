#include <stdint.h>

static inline uint64_t fBlaMka(uint64_t x, uint64_t y)
{
    const uint64_t lower_x = x & UINT64_C(0xFFFFFFFF);
    const uint64_t lower_y = y & UINT64_C(0xFFFFFFFF);
    const uint64_t product = lower_x * lower_y;
    return x + y + (product << 1);
}


int main(){
    fBlaMka(0,0);
}
