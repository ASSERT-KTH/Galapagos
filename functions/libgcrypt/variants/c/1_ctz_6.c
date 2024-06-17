#include <stdint.h>

int ctz(uint64_t in)
{
 if (in == 0) return 64;
 int r = 0;
 while ((in & (1ULL << r)) == 0)
 {
  r++;
 }
 return r;
}


int main(){
    ctz(0);
}