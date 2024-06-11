#include <stdint.h>

static uint64_t BitInterleave(uint64_t Ai)
{
    uint64_t t0 = Ai & 0xFFFFFFFF, t1 = Ai >> 32;
    
    t0 = (t0 | (t0 << 16)) & 0x0000FFFF0000FFFF;
    t0 = (t0 | (t0 << 8)) & 0x00FF00FF00FF00FF;
    t0 = (t0 | (t0 << 4)) & 0x0F0F0F0F0F0F0F0F;
    t0 = (t0 | (t0 << 2)) & 0x3333333333333333;
    t0 = (t0 | (t0 << 1)) & 0x5555555555555555;
    
    t1 = (t1 | (t1 << 16)) & 0x0000FFFF0000FFFF;
    t1 = (t1 | (t1 << 8)) & 0x00FF00FF00FF00FF;
    t1 = (t1 | (t1 << 4)) & 0x0F0F0F0F0F0F0F0F;
    t1 = (t1 | (t1 << 2)) & 0x3333333333333333;
    t1 = (t1 | (t1 << 1)) & 0x5555555555555555;

    return (t0 << 1) | t1;
}


int main(){
    BitInterleave(0);
}
