#include <stdint.h>

static int int16_t_nonzero_mask(int16_t x)
{
    int mask = (x != 0);
    return (mask << 31) >> 31;
}


int main(){
    int16_t_nonzero_mask(0);
}
