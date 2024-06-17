#include <stdint.h>

int fpr_lt(uint64_t x, uint64_t y) {
    int64_t sx = (int64_t)x;
    int64_t sy = (int64_t)y;

    if (((sx ^ sy) < 0) && (sx < 0)) {
        return 1;
    }
    return sx < sy;
}


int main(){
    fpr_lt(0,0);
}