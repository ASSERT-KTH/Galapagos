#include <stdint.h>

static uint64_t BitInterleave(uint64_t Ai)
{
    uint64_t x = Ai & 0x5555555555555555;
    uint64_t y = (Ai >> 1) & 0x5555555555555555;
    uint64_t result = x | (y << 1);
    result = (result | (result >> 1)) & 0x3333333333333333;
    result = (result | (result >> 2)) & 0x0f0f0f0f0f0f0f0f;
    result = (result | (result >> 4)) & 0x00ff00ff00ff00ff;
    result = (result | (result >> 8)) & 0x0000ffff0000ffff;
    result = (result | (result >> 16)) & 0x00000000ffffffff;
    return result;
}


int main(){
    BitInterleave(0);
}
