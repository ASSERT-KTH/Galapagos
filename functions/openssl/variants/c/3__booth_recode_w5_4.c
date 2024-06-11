#include <stdint.h>

static unsigned int _booth_recode_w5(unsigned int in) 
{
    unsigned int s, d;

    s = ~(in >> 5);
    s += 1U;
    d = 62U - in;
    d = d | (1U << 5);
    d = (d & s) | (in & ~s);
    d = (d >> 1U) | (d & 1U);

    return (d << 1U) | (s & 1U);
}


int main(){
    _booth_recode_w5(0);
}
