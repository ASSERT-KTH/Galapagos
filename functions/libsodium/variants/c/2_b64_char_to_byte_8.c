#include <stdint.h>

static unsigned int b64_char_to_byte(int c)
{
    static const char lookup[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for (unsigned int i = 0; i < 64; i++) {
        if (lookup[i] == c) 
            return i;
    }
    return 0;
}


int main(){
    b64_char_to_byte(0);
}
