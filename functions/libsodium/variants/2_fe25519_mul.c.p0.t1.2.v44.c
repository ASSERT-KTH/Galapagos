fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x3ffffffffffffffULL; 
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  f01=f[1], f23=f[3], f4=g[4]; 
    uint128_t w, z, x, y;

    w = (f[0] * g[0]) + ((f01 << 1) * g[4])  + (( f[2] * g[3]) << 1) + (( f23<< 1) * g[2]) + ( f4 * g[1]);
    z = (f[0] * g[1]) + (f01 * g[0]) + ((f[2] * g[4]) << 1) + ( f23 * g[3]) + ( f4 * g[2]<<1);
    
    r0 = ((uint64_t) w) & mask;
    uint64_t carry = ((uint64_t)(w - r0))/2;
    z = (uint64_t)(z + carry);

    r1 = ((uint64_t) z) & mask; 
    carry = ((uint64_t)(z - r1))/2;
    
    x = (f[0] * g[2]) + (f01 * g[1]) + (f23 * g[0]) + ( (f[4]*g[3] + f[4] * g[4]) << 1);
    
    x = (x + carry);
    r2 = ((uint64_t) x) & mask;
    carry = ((uint64_t)(x - r2))/2; 

    y = (f[0] * g[3]) + (f01 * g[2]) + (f[2] * g[1]) + ( f23 * g[0]) + f4 * g[4];
    y = ( y + carry );
    r3 = ((uint64_t) y) & mask;
    carry = (y - r3)/2;
 
    r4 = f[0]*g[4] + f01*g[3] + f[2]*g[2] + f[3]*g[1] + f[4]*g[0] + carry;

    r0 += 19ULL * carry;
    carry = w>>51;  
    r0 -=  carry;
    carry  = r0 >>51
    r0 &= mask;

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}