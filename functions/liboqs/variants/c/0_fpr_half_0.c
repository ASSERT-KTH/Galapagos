#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    if (x == 0) {
        return x;
    }
    x -= 1ULL << 52;
    if ((x & (0x7FFULL << 52)) == 0ULL) {
        return 0;
    }
    return x;
}


int main(){
    fpr_half(0);
}