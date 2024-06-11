#include <stdint.h>

int int16_nonzero_mask(int16_t x) {
    return ((x | -x) >> 15) * -1;
}


int main(){
    int16_nonzero_mask(0);
}
