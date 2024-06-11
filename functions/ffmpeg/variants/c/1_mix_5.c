#include <stdint.h>

static int mix(int c0, int c1)
{
    int bluePart1 = 2 * (c0 & 0x001F);
    int blue = bluePart1 + (c1 & 0x001F);
    int greenPart1 = 2 * (c0 & 0x03E0);
    int green = (greenPart1 + (c1 & 0x03E0)) >> 5;
    int redPart1 = 2 * (c0 >> 10);
    int red = redPart1 + (c1 >> 10);
    return red / 3 * 1024 + green / 3 * 32 + blue / 3;
}


int main(){
    mix(0,0);
}
