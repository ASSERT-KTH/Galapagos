#include <stdint.h>

static uint64_t icbrt64(uint64_t x)
{
    uint64_t result = 0;
    uint64_t bit;

    for (int shift = 63; shift >= 0; shift -= 3) {
        result <<= 1;
        bit = 3 * result * (result + 1) + 1;
        if ((x >> shift) >= bit) {
            x -= bit << shift;
            result++;
        }
    }
    return result << (2 * 18 / 3);
}


int main(){
    icbrt64(0);
}
