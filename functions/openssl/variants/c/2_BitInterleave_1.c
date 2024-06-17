#include <stdint.h>

static uint64_t BitInterleave(uint64_t Ai)
{
    uint64_t interleaved = 0;
    for (int i = 0; i < 32; ++i) {
        interleaved |= ((Ai >> (2 * i)) & 1UL) << i;
        interleaved |= ((Ai >> (2 * i + 1)) & 1UL) << (32 + i);
    }
    return interleaved;
}


int main(){
    BitInterleave(0);
}