#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    uint64_t mask = x == 0 ? 0 : 0xFFFFFFFFFFFFFFFF;
    x -= mask & ((uint64_t)1 << 52);
    mask = (((uint32_t)(x >> 52) & 0x7FF) + 1) >> 11;
    return x & (uint64_t)mask - 1;
}


int main(){
    fpr_half(0);
}
