#include <stdint.h>

int int16_nonzero_mask(int16_t x) {
    return -((x >> 15) | ((-x) >> 15));
}


int main(){
    int16_nonzero_mask(0);
}
