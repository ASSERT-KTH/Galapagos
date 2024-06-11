#include <stdint.h>

static uint64_t fpr_half(uint64_t x) {
    if (x != 0) {
        x -= 1ULL << 52;
        if (((x >> 52) & 0x7FF) == 0) {
            return 0;
        }
    }
    return x;
}


int main(){
    fpr_half(0);
}
