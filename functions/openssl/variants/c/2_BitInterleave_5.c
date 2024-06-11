#include <stdint.h>

static uint64_t BitInterleave(uint64_t Ai)
{
    uint64_t evenBits = Ai & 0x5555555555555555;
    uint64_t oddBits = (Ai >> 1) & 0x5555555555555555;
    evenBits |= evenBits >> 1; evenBits &= 0x3333333333333333;
    evenBits |= evenBits >> 2; evenBits &= 0x0F0F0F0F0F0F0F0F;
    evenBits |= evenBits >> 4; evenBits &= 0x00FF00FF00FF00FF;
    evenBits |= evenBits >> 8; evenBits &= 0x0000FFFF0000FFFF;
    oddBits |= oddBits >> 1; oddBits &= 0x3333333333333333;
    oddBits |= oddBits >> 2; oddBits &= 0x0F0F0F0F0F0F0F0F;
    oddBits |= oddBits >> 4; oddBits &= 0x00FF00FF00FF00FF;
    oddBits |= oddBits >> 8; oddBits &= 0x0000FFFF0000FFFF;
    oddBits <<= 16;
    return (evenBits << 16) | oddBits;
}


int main(){
    BitInterleave(0);
}
