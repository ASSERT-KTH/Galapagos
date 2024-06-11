#include <stdint.h>

static unsigned int b64_urlsafe_char_to_byte(int c)
{
    if ('A' <= c && c <= 'Z')
        return c - 65;
    if ('a' <= c && c <= 'z')
        return c - 71;
    if ('0' <= c && c <= '9')
        return c + 4;
    if (c == '-')
        return 62;
    if (c == '_')
        return 63;
    return 0;
}


int main(){
    b64_urlsafe_char_to_byte(0);
}
