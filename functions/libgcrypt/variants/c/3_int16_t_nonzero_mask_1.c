#include <stdint.h>

static int int16_t_nonzero_mask(int16_t x)
{
    uint32_t v = (uint32_t)(x & 0xFFFF);
    v = ~v + 1;
    v >>= 31;
    return v & 1;
}


int main(){
    int16_t_nonzero_mask(0);
}
