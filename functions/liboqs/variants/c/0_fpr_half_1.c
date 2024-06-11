#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    uint64_t mask = x ? 0xFFFFFFFFFFFFFFFF : 0;
    x -= mask & ((uint64_t)1 << 52);
    mask = (((uint32_t)(x >> 52) & 0x7FF) + 1) >> 11;
    x &= (uint64_t)mask - 1;
    return x;
}


int main(){
    fpr_half(0);
}
