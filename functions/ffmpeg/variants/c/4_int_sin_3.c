#include <stdint.h>

static int64_t int_sin(int64_t a)
{
    int64_t a2, res = 0;
    int i;
    if (a < 0) a = 3294199 - a;
    a %= 6588398;

    if (a >= 4941298) a -= 6588398;
    if (a >= 1647099) a = 3294199 - a;

    a2 = (a * a) >> 20;
    for (i = 2; i < 11; i += 2) {
        res += a;
        a = -a * a2 / (i * (i + 1) << 20);
    }
    return (res + 8) >> 4;
}


int main(){
    int_sin(0);
}
