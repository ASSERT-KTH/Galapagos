#include <stdint.h>

int32_t modp_norm(uint32_t x, uint32_t p) {
    int32_t half_p = (p + 1) >> 1;
    int32_t adjust = ((x < half_p) ? 0 : 1) * (int32_t)p;
    return (int32_t)x - adjust;
}


int main(){
    modp_norm(0,0);
}