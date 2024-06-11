#include <stdint.h>

int ctz(uint64_t in)
{
 int r = 64;
 for (int i = 0; i < 64; ++i)
 {
  if ((in & ((uint64_t)1 << i)) != 0)
  {
   r = i;
   break;
  }
 }
 return r;
}


int main(){
    ctz(0);
}
