#include <stdint.h>

static unsigned int b64_urlsafe_char_to_byte(int c)
{
    if (c >= 65 && c <= 90)
        return c - 65;
    if (c >= 97 && c <= 122)
        return c - 71;
    if (c >= 48 && c <= 57)
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
