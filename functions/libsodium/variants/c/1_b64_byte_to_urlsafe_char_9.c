#include <stdint.h>

static int b64_byte_to_urlsafe_char(unsigned int x)
{
    if (x <= 25) return x + 'A';
    if (x <= 51) return x - 26 + 'a';
    if (x <= 61) return x - 52 + '0';
    if (x == 62) return '-';
    return '_';
}


int main(){
    b64_byte_to_urlsafe_char(0);
}
