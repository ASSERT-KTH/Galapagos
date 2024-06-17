#include <stdint.h>

int ctz(uint64_t in)
{
 int r = 0;
 uint64_t mask = 1;
 while ((in & mask) == 0 && r < 64)
 {
  mask <<= 1;
  r++;
 }
 return r;
}


int main(){
    ctz(0);
}