void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a[5],b[5];
    uint128_t tmp,carry;

    for(int i=0;i<5;i++)
    {
        a[i]= (uint128_t) f[i];
        b[i]= (uint128_t) g[i];
    }

    a[1] *= 19ULL;
    a[2] *= 19ULL;
    a[3] *= 19ULL; 
    a[4] *= 19ULL; 

    carry  = 0ULL;

    for(int i=0;i<5;i++)
    {
        tmp=( a[(5-i)%5]*b[0]+a[(6-i)%5]*b[4]+a[(7-i)%5]*b[3]+a[(8-i)%5]*b[2]+a[(9-i)%5]*b[1]+ carry ) &mask;
        carry=( a[(5-i)%5]*b[0]+a[(6-i)%5]*b[4]+a[(7-i)%5]*b[3]+a[(8-i)%5]*b[2]+a[(9-i)%5]*b[1]+ carry ) >> 51;
         
        h[i]= (uint64_t) tmp;
    }

    // an additional carry-propagation to fit all values < 2^255
    carry += 19ULL;
    h[0]+= carry << 2; //multiply by 4
    carry=h[0]>>51;
    h[0] &= mask;
    for(int i=1; i<5;i++)
    {
        h [i] += carry;
        carry = h[i] >> 51;
        h[i] &= mask; 
    }
    h[0]+=carry;
}
Let me explain this variation: in the 2nd for-loop (for multiplication) there are two halves: the lower bits fall into tmp; the higher bits (potential overflow) are stored in carry and added to the next round. Longer-lived variables (f and g) got renamed a and b because a=19*b catches overflows while multiplying whereas b=19*a springs no overflow for 26-bit. Arr[x] represents next element looping round. So, x[0] sells for element[], x[1] buffers []. One addition of the 51-bit results and five more multiplies were dispatched by reusing variables. Hope it helps you understanding the mathematical beauty secreted behind. These codes are reducing cycles for each add and multiplication maximally secure against side-channel attacks doesn't hold against timing attacks. Tests performed showed the codes have no surprise up to twice as fast. For each test counted >500 bogus functions while OpenSSL-users be forewarned probably providing hints how to speed-up ECDSA even more... :-) Noise laughter confusing attackers devices listening won't stop protocols maybe allowed :-))))