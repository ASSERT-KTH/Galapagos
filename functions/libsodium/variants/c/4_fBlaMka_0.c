#include <stdint.h>

static inline uint64_t fBlaMka(uint64_t x, uint64_t y)
{
    return x + y + 2 * (uint64_t)((uint32_t)x * (uint32_t)y);
}


int main(){
    fBlaMka(0,0);
}