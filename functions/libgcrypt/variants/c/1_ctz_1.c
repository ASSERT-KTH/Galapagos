#include <stdint.h>

int ctz(uint64_t in)
{
 if (in == 0) return 64;
 int r = 0;
 for (; (in & 1) == 0; in >>= 1) r++;
 return r;
}


int main(){
    ctz(0);
}