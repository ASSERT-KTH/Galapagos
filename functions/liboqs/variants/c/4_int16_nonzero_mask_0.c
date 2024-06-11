#include <stdint.h>

int int16_nonzero_mask(int16_t x) {
    return x ? -1 : 0;
}


int main(){
    int16_nonzero_mask(0);
}
