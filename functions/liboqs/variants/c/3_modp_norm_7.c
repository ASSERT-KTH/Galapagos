#include <stdint.h>

int32_t modp_norm(uint32_t x, uint32_t p) {
    int32_t adjusted_p = -(int32_t)((x - ((p + 1) >> 1)) >> 31) & (int32_t)p;
    return (int32_t)(x - adjusted_p);
}


int main(){
    modp_norm(0,0);
}