#include <stdint.h>

static int64_t int_sin(int64_t a)
{
    int64_t a2, res = 0;
    int i;
    if (a < 0) a = 3294199 - a;
    a %= 3294199 << 1;

    if (a >= 4941298) a -= 3294199 << 1;
    if (a >= 1647099) a = 3294199 - a;

    a2 = ((a * a) / (1 << 10)) >> 10;
    for (i = 2; i < 11; i += 2) {
        res += a;
        a = -a * a2 / ((1 << 20) * i * (i + 1));
    }
    return (res + 8) >> 4;
}


int main(){
    int_sin(0);
}
