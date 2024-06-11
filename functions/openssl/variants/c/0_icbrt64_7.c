#include <stdint.h>

static uint64_t icbrt64(uint64_t x)
{
    uint64_t result = 0;
    uint64_t b;
    int s;

    for (s = 63; s >= 0; s -= 3) {
        result = (result << 1) & 0xFFFFFFFFFFFFFFFF;
        b = 3 * result * (result + 1) + 1;
        if ((x >> s) >= b) {
            x -= b << s;
            result++;
        }
    }
    return result * 1 << 12;
}


int main(){
    icbrt64(0);
}
