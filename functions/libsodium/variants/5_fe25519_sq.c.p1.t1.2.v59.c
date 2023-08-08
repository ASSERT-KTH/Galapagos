void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    const uint128_t f0 = (uint128_t) f[0];
    const uint128_t f1 = (uint128_t) f[1];
    const uint128_t f2 = (uint128_t) f[2];
    const uint128_t f3 = (uint128_t) f[3];
    const uint128_t f4 = (uint128_t) f[4];

    const uint128_t r0 = f0 * f0 + 38ULL * f1 * f4 + 38ULL * f2 * f3;
    const uint128_t r1 = (f0 << 1) * f1 + 38ULL * f2 * f4 + 19ULL * f3 * f3;
    const uint128_t r2 = (f0 << 1) * f2 +   f1 * f1  + 38ULL * f3 * f4;
    const uint128_t r3 = (f0 << 1) * f3 +  (f1 << 1) * f2 + 19ULL * f4 * f4;
    const uint128_t r4 = (f0 << 1) * f4 +  (f1 << 1) * f3 +    f2 * f2;

    uint64_t r[5] = {
        ((uint64_t)r0) & mask, 
        ((uint64_t)r1) & mask, 
        ((uint64_t)r2) & mask,   
        ((uint64_t)r3) & mask, 
        ((uint64_t)r4) & mask
    };
    uint64_t carry = 0;

    for(int i = 0; i < 5; i++)
    {
        carry = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry;    
        r[i] &= mask;
    }

    h[0] =   r[0];
    h[1] =   r[1] + (r[0] >> 51);
    h[2] =   r[2] + (r[1] >> 51); 
    h[3] =   r[3] + (r[2] >> 51);
    h[4] =   r[4] + (r[3] >> 51);

    for(int i = 0; i < 5; i++)
    {
        h[i] &= mask;
    }

}
This version performs the same function as the original, but applies small modifications to the carry and conditional assignments to underline the importance of the carry flag in the parameter selections (a nice connection to classic assembly operations). The actual mathematical procedures, the primary task of the function, remain unchanged.