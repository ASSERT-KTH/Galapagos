#include <stdint.h>

static unsigned int b64_char_to_byte(int c)
{
    static const unsigned int lookup[] = {
        ['+'] = 62, ['/'] = 63
    };
    
    if ('A' <= c && c <= 'Z') return c - 'A';
    if ('a' <= c && c <= 'z') return c - 'a' + 26;
    if ('0' <= c && c <= '9') return c - '0' + 52;
    if (c == '+' || c == '/') return lookup[c];
    return 0;
}


int main(){
    b64_char_to_byte(0);
}
