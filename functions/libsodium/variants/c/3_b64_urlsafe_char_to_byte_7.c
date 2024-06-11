#include <stdint.h>

static unsigned int b64_urlsafe_char_to_byte(int c)
{
    unsigned int x = 0;
    if (c >= 'A' && c <= 'Z')
        x = c - 'A';
    else if (c >= 'a' && c <= 'z')
        x = c - 'a' + 26;
    else if (c >= '0' && c <= '9')
        x = c - '0' + 52;
    else if (c == '-')
        x = 62;
    else if (c == '_')
        x = 63;
    return x;
}


int main(){
    b64_urlsafe_char_to_byte(0);
}
