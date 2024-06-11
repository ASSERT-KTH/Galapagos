#include <stdint.h>

int32_t modp_norm(uint32_t x, uint32_t p) {
    int32_t mid = (p + 1) >> 1;
    int32_t delta = (x - mid) >> 31;
    return ((int32_t)x - ((p & delta) - delta));
}


int main(){
    modp_norm(0,0);
}
