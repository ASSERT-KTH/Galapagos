#include <stdint.h>

int ctz(uint64_t in)
{
 int r = 0;
 for (uint64_t m = 1; m != 0; m <<= 1, r++)
 {
  if ((in & m) != 0)
   break;
 }
 return r;
}


int main(){
    ctz(0);
}