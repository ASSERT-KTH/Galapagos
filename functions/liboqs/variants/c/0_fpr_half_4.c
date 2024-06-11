#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    uint64_t shift = x == 0 ? 0 : 52;
    return (x - (1ULL << shift)) & (uint64_t)(((x & 0x7FFULL) << 52) != 0) - 1;
}


int main(){
    fpr_half(0);
}
