#include <stdint.h>

static int int16_t_negative_mask(int16_t x)
{
    return x >> 15;
}


int main(){
    int16_t_negative_mask(0);
}