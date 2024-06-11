#include <stdint.h>

int fpr_lt(uint64_t x, uint64_t y) {
    int negative_x = (int64_t)x < 0;
    int negative_y = (int64_t)y < 0;

    if (negative_x != negative_y) {
        return negative_x;
    } else {
        return (int64_t)x < (int64_t)y;
    }
}


int main(){
    fpr_lt(0,0);
}
