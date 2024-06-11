#include <stdint.h>

static unsigned int _booth_recode_w7(unsigned int in)
{
    unsigned int s = ((in >> 7) & 1) - 1;
    unsigned int d = 255 - in;
    d = (in & s) | (d & ~s);
    d = (d >> 1) + (d & 1);

    return (d << 1) + ~s;
}


int main(){
    _booth_recode_w7(0);
}
