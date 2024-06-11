#include <stdint.h>

int ctz(uint64_t in)
{
 int r = 0;
 if (in == 0) return 64;
 for (uint64_t m = 1; (in & m) == 0; m <<= 1) r++;
 return r;
}


int main(){
    ctz(0);
}
