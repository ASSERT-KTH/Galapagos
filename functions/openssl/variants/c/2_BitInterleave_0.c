#include <stdint.h>

static uint64_t BitInterleave(uint64_t Ai)
{
    uint64_t result = 0;
    for (int i = 0; i < 32; ++i) {
        result |= ((Ai >> i) & 1) << (2 * i);
        result |= ((Ai >> (i + 32)) & 1) << (2 * i + 1);
    }
    return result;
}


int main(){
    BitInterleave(0);
}