#include <stdint.h>

static unsigned int _booth_recode_w7(unsigned int in)
{
    unsigned int s = -((in >> 7) & 1);
    unsigned int d = ~in;
    d = (d + 1) & s | in & ~s;
    d = ((d + 1) >> 1);

    return (d << 1) | ((in >> 7) & 1);
}


int main(){
    _booth_recode_w7(0);
}