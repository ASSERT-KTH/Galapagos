#include <stdint.h>

uint32_t modp_montymul(uint32_t a, uint32_t b, uint32_t p, uint32_t p0i) {
    uint64_t z = (uint64_t)a * (uint64_t)b;
    uint64_t w = (z * p0i & 0x7FFFFFFF) * p;
    uint32_t d = (uint32_t)((z + w) >> 31);
    return d >= p ? d - p : d;
}


int main(){
    modp_montymul(0,0,0,0);
}
