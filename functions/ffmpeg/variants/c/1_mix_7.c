#include <stdint.h>

static int mix(int c0, int c1)
{
    int blue = (c0 & 0x001F) + (c0 & 0x001F) + (c1 & 0x001F);
    int green = ((c0 & 0x03E0) + (c0 & 0x03E0) + (c1 & 0x03E0)) >> 5;
    int red = (c0 >> 10) + (c0 >> 10) + (c1 >> 10);
    return (red / 3) * 1024 + (green / 3) * 32 + (blue / 3);
}


int main(){
    mix(0,0);
}
