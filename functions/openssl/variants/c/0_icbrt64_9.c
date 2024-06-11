#include <stdint.h>

static uint64_t icbrt64(uint64_t x)
{
    uint64_t r = 0;
    uint64_t b;

    for (int s = 64 - 1; s >= 0; s -= 3) {
        r <<= 1;
        b = 3 * r * (r + 1) + 1;
        if ((x >> s) >= b) {
            x -= b << s;
            r++;
        }
    }
    return r << ((2 * 18) / 3);
}


int main(){
    icbrt64(0);
}
