#include <stdint.h>

static int b64_byte_to_char(unsigned int x)
{
    char table[] = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
    return table[x];
}


int main(){
    b64_byte_to_char(0);
}
