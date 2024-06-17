#include <stdint.h>

static uint64_t BitInterleave(uint64_t Ai)
{
    uint64_t x = Ai, mask = 0x5555555555555555;
    
    x = (x | (x << 16)) & mask;
    x = (x | (x << 8)) & 0x00FF00FF00FF00FF;
    x = (x | (x << 4)) & 0x0F0F0F0F0F0F0F0F;
    x = (x | (x << 2)) & 0x3333333333333333;
    x = (x | (x << 1)) & 0x5555555555555555;

    return x | (x << 1);
}


int main(){
    BitInterleave(0);
}