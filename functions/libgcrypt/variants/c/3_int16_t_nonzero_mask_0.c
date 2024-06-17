#include <stdint.h>

static int int16_t_nonzero_mask(int16_t x)
{
    uint32_t v = (uint32_t)(x) << 16;
    v = -(v >> 16);
    v >>= 31;
    return -v;
}


int main(){
    int16_t_nonzero_mask(0);
}