#include <stdint.h>

static uint64_t BitDeinterleave(uint64_t Ai)
{
    uint64_t even = 0, odd = 0;
    for (int i = 0; i < 32; i++) {
        even |= ((Ai >> (2 * i)) & 1) << i;
        odd |= ((Ai >> (2 * i + 1)) & 1) << i;
    }
    return (odd << 32) | even;
}


int main(){
    BitDeinterleave(0);
}
