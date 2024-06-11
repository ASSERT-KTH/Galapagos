#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    uint64_t exp_mask = 0x7FFULL << 52;
    if (x == 0 || (x & exp_mask) == 0) {
        return x;
    }
    x -= 1ULL << 52;
    if ((x & exp_mask) == 0) {
        return 0;
    }
    return x;
}


int main(){
    fpr_half(0);
}
