#include <stdint.h>

static inline uint64_t fBlaMka(uint64_t x, uint64_t y)
{
    const uint32_t low_x = (uint32_t)x;
    const uint32_t low_y = (uint32_t)y;
    const uint64_t product = (uint64_t)low_x * low_y;
    return x + y + (product << 1);
}


int main(){
    fBlaMka(0,0);
}