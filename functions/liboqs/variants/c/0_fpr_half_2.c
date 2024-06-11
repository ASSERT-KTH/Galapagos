#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    return x == 0 ? x : ((x - (1ULL << 52)) & ~((x >> 63) << 63));
}


int main(){
    fpr_half(0);
}
