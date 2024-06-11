#include <stdint.h>

static uint64_t BitInterleave(uint64_t Ai)
{
    uint64_t odd = Ai & 0xAAAAAAAAAAAAAAAA;
    uint64_t even = Ai & 0x5555555555555555;
    
    odd |= odd >> 1;
    even |= even << 1;
    
    odd &= 0x3333333333333333;
    even &= 0xCCCCCCCCCCCCCCCC;
    
    odd |= odd >> 2;
    even |= even << 2;
    
    odd &= 0x0F0F0F0F0F0F0F0F;
    even &= 0xF0F0F0F0F0F0F0F0;
    
    odd |= odd >> 4;
    even |= even << 4;
    
    odd &= 0x00FF00FF00FF00FF;
    even &= 0xFF00FF00FF00FF00;
    
    odd |= odd >> 8;
    even |= even << 8;
    
    odd &= 0x0000FFFF0000FFFF;
    even &= 0xFFFF0000FFFF0000;
    
    odd |= odd >> 16;
    even |= even << 16;
    
    odd &= 0x00000000FFFFFFFF;
    even &= 0xFFFFFFFF00000000;

    return odd | even;
}


int main(){
    BitInterleave(0);
}
