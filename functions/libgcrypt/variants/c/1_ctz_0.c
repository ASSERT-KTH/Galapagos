#include <stdint.h>

int ctz(uint64_t in)
{
 int r = 0;
 while ((in >> r) & 1 == 0 && r < 64) r++;
 return r;
}


int main(){
    ctz(0);
}
