#include <stdint.h>

static unsigned int _booth_recode_w5(unsigned int in) 
{
    unsigned int s, d;

    s = ~(in >> 5) + 1;
    d = (1 << 6) - in - 1;
    d = (d & s) | (in & ~s);
    d = (d >> 1) + (d & 1);

    return (d << 1) | (s & 1);
}


int main(){
    _booth_recode_w5(0);
}
