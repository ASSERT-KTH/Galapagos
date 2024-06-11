#include <stdint.h>

static uint64_t BitDeinterleave(uint64_t Ai)
{
    uint64_t lo = Ai & 0x5555555555555555;
    uint64_t hi = (Ai >> 1) & 0x5555555555555555;
    lo = (lo | (lo >> 1)) & 0x3333333333333333;
    lo = (lo | (lo >> 2)) & 0x0f0f0f0f0f0f0f0f;
    lo = (lo | (lo >> 4)) & 0x00ff00ff00ff00ff;
    lo = (lo | (lo >> 8)) & 0x0000ffff0000ffff;
    lo = (lo | (lo >> 16)) & 0x00000000ffffffff;
    hi = (hi | (hi >> 1)) & 0x3333333333333333;
    hi = (hi | (hi >> 2)) & 0x0f0f0f0f0f0f0f0f;
    hi = (hi | (hi >> 4)) & 0x00ff00ff00ff00ff;
    hi = (hi | (hi >> 8)) & 0x0000ffff0000ffff;
    hi = (hi | (hi >> 16)) & 0x00000000ffffffff;
    return (hi << 32) | lo;
}


int main(){
    BitDeinterleave(0);
}
