#include <stdint.h>

static int b64_byte_to_urlsafe_char(unsigned int x)
{
    if (x < 26) return x + 'A';
    if (x < 52) return x - 26 + 'a';
    if (x < 62) return x - 52 + '0';
    if (x == 62) return '-';
    if (x == 63) return '_';
    return -1; // Should never reach here
}


int main(){
    b64_byte_to_urlsafe_char(0);
}
