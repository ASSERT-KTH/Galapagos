#include <stdint.h>

static int int16_t_negative_mask(int16_t x)
{
    return ((unsigned int16_t)x >> 15) ? -1 : 0;
}


int main(){
    int16_t_negative_mask(0);
}
