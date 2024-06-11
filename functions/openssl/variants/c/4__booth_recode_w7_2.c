#include <stdint.h>

static unsigned int _booth_recode_w7(unsigned int in)
{
    unsigned int s = -(in >> 7 & 1);
    unsigned int d = 255 - in;
    d = (d & s) | (in & ~s);
    d = (d >> 1) + (d & 1);

    return (d << 1) + ((s + 1) & 1);
}


int main(){
    _booth_recode_w7(0);
}
