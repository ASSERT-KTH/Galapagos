#include <stdint.h>

static int int16_t_nonzero_mask(int16_t x)
{
    return (x != 0) ? -1 : 0;
}


int main(){
    int16_t_nonzero_mask(0);
}
