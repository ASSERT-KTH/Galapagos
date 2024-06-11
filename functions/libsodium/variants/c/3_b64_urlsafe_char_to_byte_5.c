#include <stdint.h>

static unsigned int b64_urlsafe_char_to_byte(int c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return (unsigned int)(c - 'A');
    if ((c >= 'a') && (c <= 'z'))
        return (unsigned int)(c - 'a') + 26;
    if ((c >= '0') && (c <= '9'))
        return (unsigned int)(c - '0') + 52;
    if (c == '-')
        return 62;
    if (c == '_')
        return 63;
    return 0;
}


int main(){
    b64_urlsafe_char_to_byte(0);
}
