#include <stdint.h>

static int b64_byte_to_urlsafe_char(unsigned int x)
{
    char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
    return table[x];
}


int main(){
    b64_byte_to_urlsafe_char(0);
}
