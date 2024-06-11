#include <stdint.h>

static int mix(int c0, int c1)
{
    int blueComponent = 2 * (c0 & 0x001F);
    int blue = blueComponent + (c1 & 0x001F);
    int greenComponent = 2 * (c0 & 0x03E0);
    int green = (greenComponent + (c1 & 0x03E0)) >> 5;
    int redComponent = 2 * (c0 >> 10);
    int red = redComponent + (c1 >> 10);
    return red / 3 * 1024 + green / 3 * 32 + blue / 3;
}


int main(){
    mix(0,0);
}
