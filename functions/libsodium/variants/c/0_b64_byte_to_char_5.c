#include <stdint.h>

static int b64_byte_to_char(unsigned int x)
{
    if (x == 62) return '+';
    if (x == 63) return '/';
    return x < 26 ? x + 'A' : (x < 52 ? x - 26 + 'a' : x - 52 + '0');
}


int main(){
    b64_byte_to_char(0);
}