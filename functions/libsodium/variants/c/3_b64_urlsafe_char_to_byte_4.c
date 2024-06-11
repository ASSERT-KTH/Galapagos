#include <stdint.h>

static unsigned int b64_urlsafe_char_to_byte(int c)
{
    if (('A' <= c) && (c <= 'Z'))
        return c - 'A';
    if (('a' <= c) && (c <= 'z'))
        return c - 'a' + 26;
    if (('0' <= c) && (c <= '9'))
        return c - '0' + 52;
    if (c == '-')
        return 62;
    return (c == '_') ? 63 : 0;
}


int main(){
    b64_urlsafe_char_to_byte(0);
}
