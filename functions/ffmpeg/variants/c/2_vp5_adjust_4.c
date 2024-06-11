#include <stdint.h>

static int vp5_adjust(int v, int t)
{
    int s1 = v >> 31;
    int abs_v = (v ^ s1) - s1;
    if (abs_v >= 2 * t) abs_v = 0;
    abs_v -= t;
    int s2 = abs_v >> 31;
    abs_v = (abs_v ^ s2) - s2;
    return ((t - abs_v) ^ s1) + s1;
}


int main(){
    vp5_adjust(0,0);
}
