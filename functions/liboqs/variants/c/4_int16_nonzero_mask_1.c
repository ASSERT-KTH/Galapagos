#include <stdint.h>

int int16_nonzero_mask(int16_t x) {
    return (!(x == 0)) - 1;
}


int main(){
    int16_nonzero_mask(0);
}
