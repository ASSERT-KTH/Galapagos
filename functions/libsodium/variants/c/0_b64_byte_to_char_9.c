#include <stdint.h>

static int b64_byte_to_char(unsigned int x)
{
    char lookup[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    return lookup[x];
}


int main(){
    b64_byte_to_char(0);
}
