#include <stdint.h>

static int b64_byte_to_urlsafe_char(unsigned int x)
{
    if (x < 26) return 'A' + x;
    if (x < 52) return 'a' + (x - 26);
    if (x < 62) return '0' + (x - 52);
    return x == 62 ? '-' : '_';
}


int main(){
    b64_byte_to_urlsafe_char(0);
}
