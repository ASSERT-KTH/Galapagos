#include <stdint.h>

static uint64_t BitDeinterleave(uint64_t Ai)
{
    uint64_t t = Ai & 0xaaaaaaaa;
    t = (t | (t >> 1)) & 0x3333333333333333;
    t = (t | (t >> 2)) & 0x0f0f0f0f0f0f0f0f;
    t = (t | (t >> 4)) & 0x00ff00ff00ff00ff;
    t = (t | (t >> 8)) & 0x0000ffff0000ffff;
    t = (t | (t >> 16)) & 0x00000000ffffffff;
    uint64_t t2 = Ai & 0x55555555;
    t2 = (t2 | (t2 << 1)) & 0x3333333333333333;
    t2 = (t2 | (t2 << 2)) & 0x0f0f0f0f0f0f0f0f;
    t2 = (t2 | (t2 << 4)) & 0x00ff00ff00ff00ff;
    t2 = (t2 | (t2 << 8)) & 0x0000ffff0000ffff;
    t2 = t2 | (t2 << 16);
    return (t << 32) | (t2 & 0x00000000ffffffff);
}


int main(){
    BitDeinterleave(0);
}
