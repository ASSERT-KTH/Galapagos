#include <stdint.h>

static unsigned int _booth_recode_w5(unsigned int in)
{
    unsigned int s, d;

    s = ~((in >> 5) - 1);
    d = 63U - in;
    d = (d & s) | (in & ~s);
    d = (d + (d & 1U)) >> 1U;

    return (d << 1U) + (s & 1U);
}


int main(){
    _booth_recode_w5(0);
}
