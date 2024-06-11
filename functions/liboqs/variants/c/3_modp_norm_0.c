#include <stdint.h>

int32_t modp_norm(uint32_t x, uint32_t p) {
    return (int32_t)(x - (p * ((x >= ((p + 1) >> 1)) ? 1 : 0)));
}


int main(){
    modp_norm(0,0);
}
