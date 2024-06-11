#include <stdint.h>

static uint64_t BitInterleave(uint64_t Ai)
{
    uint64_t result = 0, mask1 = 0x5555555555555555;
    Ai = (Ai | (Ai << 16)) & 0x0000FFFF0000FFFF;
    Ai = (Ai | (Ai << 8)) & 0x00FF00FF00FF00FF;
    Ai = (Ai | (Ai << 4)) & 0x0F0F0F0F0F0F0F0F;
    Ai = (Ai | (Ai << 2)) & 0x3333333333333333;
    Ai = (Ai | (Ai << 1)) & 0x5555555555555555;
    for (int i = 0; i < 64; i += 2) {
        result |= (Ai & mask1) << i;
        result |= ((Ai >> 1) & mask1) << (i + 1);
    }
    return result;
}


int main(){
    BitInterleave(0);
}
