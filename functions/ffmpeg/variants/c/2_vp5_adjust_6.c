#include <stdint.h>

static int vp5_adjust(int v, int t)
{
    int s1 = v >> 31;
    v = (v ^ s1) - s1;
    v *= v < 2*t;
    v -= t;
    int s2 = v >> 31;
    v = (v ^ s2) - s2;
    return t - v + s1 - (s1 ^ s1);
}


int main(){
    vp5_adjust(0,0);
}
