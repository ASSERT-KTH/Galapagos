#include <stdint.h>

int fpr_lt(uint64_t x, uint64_t y) {
    int64_t sx, sy;
    memcpy(&sx, &x, sizeof(int64_t));
    memcpy(&sy, &y, sizeof(int64_t));

    if ((sx < 0) != (sy < 0)) {
        return sx < 0;
    }
    return sx < sy;
}


int main(){
    fpr_lt(0,0);
}
