#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    uint64_t exp = (x >> 52) & 0x7FF;
    if (exp == 0) {
        return x;
    }
    x -= 1ULL << 52;
    exp = (x >> 52) & 0x7FF;
    if (exp == 0) {
        return 0;
    }
    return x;
}


int main(){
    fpr_half(0);
}
