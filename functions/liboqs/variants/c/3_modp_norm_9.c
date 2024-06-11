#include <stdint.h>

int32_t modp_norm(uint32_t x, uint32_t p) {
    uint32_t half_p = (p + 1) >> 1;
    int32_t result = (x >= half_p) ? (x - p) : x;
    return (int32_t)result;
}


int main(){
    modp_norm(0,0);
}
