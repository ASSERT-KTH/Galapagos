#include <stdint.h>

static int b64_byte_to_char(unsigned int x)
{
    return ((x < 26) * (x + 'A')) |
           ((x >= 26 && x < 52) * (x - 26 + 'a')) |
           ((x >= 52 && x < 62) * (x - 52 + '0')) |
           ((x == 62) * '+') |
           ((x == 63) * '/');
}


int main(){
    b64_byte_to_char(0);
}
