#include <stdint.h>

static unsigned int _booth_recode_w7(unsigned int in)
{
    unsigned int s = (-(in >> 7)) & 1;
    unsigned int d = (1 << 8) - in - 1;
    unsigned int temp = d & s | in & ~s;
    d = (temp >> 1) + (temp & 1);

    return (d << 1) | s;
}


int main(){
    _booth_recode_w7(0);
}
