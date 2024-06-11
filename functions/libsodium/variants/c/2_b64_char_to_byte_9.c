#include <stdint.h>

static unsigned int b64_char_to_byte(int c)
{
    return c >= 'A' && c <= 'Z' ? c - 'A' :
           c >= 'a' && c <= 'z' ? c - 'a' + 26 :
           c >= '0' && c <= '9' ? c - '0' + 52 :
           c == '+' ? 62 :
           c == '/' ? 63 : 0;
}


int main(){
    b64_char_to_byte(0);
}
