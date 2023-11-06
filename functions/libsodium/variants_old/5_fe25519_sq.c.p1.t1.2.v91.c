void fe25519_sq(fe25519 h, const fe25519 f)
{
    uint128_t g[5];
    uint64_t carry, mask = 0x7ffffffffffffULL;

    for(int i = 0; i < 5; i++)
        g[i] = (uint128_t) f[i]; 

    uint128_t gMultiplied[5] = {g[0]<<1, g[1]<<1, 38ULL*g[1], 38ULL*g[2], 38ULL*g[3]}, 
                gMultiplied19[2] = {19ULL*g[3], 19ULL*g[4]};
                
    uint128_t r[5] = { g[0]*g[0]+gMultiplied[2]*g[4]+gMultiplied[3]*g[3], 
                               gMultiplied[0]*g[1]+gMultiplied[3]*g[4]+gMultiplied19[0]*g[3], 
                               gMultiplied[0]*g[2]+g[1]*g[1]+gMultiplied[4]*g[4], 
                               gMultiplied[0]*g[3]+gMultiplied[1]*g[2]+gMultiplied19[1]*g[4], 
                               gMultiplied[0]*g[4]+gMultiplied[1]*g[3]+g[2]*g[2]};

    for(int i = 0; i < 5; i++) {
        uint64_t tempR = ((uint64_t) r[i])&mask;
        carry = (uint64_t) (r[i] >> 51);
        if(i != 4) {
            r[i+1] += carry; 
            h[i] = tempR;
        }
        else {
            h[i] = tempR + 19ULL * carry;
            carry = h[0] >> 51; 
            h[0] &= mask;
            h[1] += carry;
            carry = h[1] >> 51;
            h[1] &= mask;
            h[2] += carry;
        }
    }
}