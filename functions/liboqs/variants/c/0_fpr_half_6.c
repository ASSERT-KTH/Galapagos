#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    uint64_t subtractor = x ? (1ULL << 52) : 0;
    x -= subtractor;
    uint32_t exp = (uint32_t)(x >> 52);
    if (exp == 0) {
        return 0;
    }
    return x;
}


int main(){
    fpr_half(0);
}
