#include <stdint.h>

uint32_t modp_montymul(uint32_t a, uint32_t b, uint32_t p, uint32_t p0i) {
    uint64_t z = (uint64_t)a * b;
    uint64_t w = z * p0i;
    w &= 0x7FFFFFFF;
    w *= p;
    uint32_t d = (uint32_t)((z + w) >> 31) - p;
    if (d >> 31) d += p;
    return d;
}


int main(){
    modp_montymul(0,0,0,0);
}
