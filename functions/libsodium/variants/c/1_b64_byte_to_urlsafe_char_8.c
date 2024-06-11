#include <stdint.h>

static int b64_byte_to_urlsafe_char(unsigned int x)
{
    switch(x) {
        case 0 ... 25: return x + 'A';
        case 26 ... 51: return x - 26 + 'a';
        case 52 ... 61: return x - 52 + '0';
        case 62: return '-';
        case 63: return '_';
    }
    return -1;
}


int main(){
    b64_byte_to_urlsafe_char(0);
}
