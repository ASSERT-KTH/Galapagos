#include <stdint.h>

int32_t modp_norm(uint32_t x, uint32_t p) {
    int32_t mid = (p + 1) >> 1;
    return ((x >= mid) ? (int32_t)(x - p) : (int32_t)x);
}


int main(){
    modp_norm(0,0);
}
