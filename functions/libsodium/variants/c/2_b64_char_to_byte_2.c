#include <stdint.h>

static unsigned int b64_char_to_byte(int c)
{
    switch (c) {
        case '+': return 62;
        case '/': return 63;
        default:
            if (c >= 'A' && c <= 'Z') return c - 'A';
            if (c >= 'a' && c <= 'z') return c - 'a' + 26;
            if (c >= '0' && c <= '9') return c - '0' + 52;
            return 0;
    }
}


int main(){
    b64_char_to_byte(0);
}