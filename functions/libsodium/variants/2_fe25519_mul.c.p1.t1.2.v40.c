Here is a very similar code to your original function with some safeties, checking if inputs are not NULL, with the same functionality:


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    if(h == NULL || f == NULL || g == NULL) return;

    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  v0, v1, v2, v3, v4;
    uint64_t  c0, c1, c2, c3;
    uint64_t  carry;

    v0 = (uint128_t) f[0] * g[0];
    v1 = (uint128_t) f[1] * g[1];
    v2 = (uint128_t) f[2] * g[2];
    v3 = (uint128_t) f[3] * g[3];
    v4 = (uint128_t) f[4] * g[4];

    r0 = v0 + 19 * (f[1] * g[4] + f[2] * g[3] + f[3] * g[2] + f[4] * g[1]);
    r1 = v1 + 19 * (f[2] * g[4] + f[3] * g[3] + f[4] * g[2]) + f[0] * g[1];
    r2 = v2 + 19 * (f[3] * g[4] + f[4] * g[3]) + f[0] * g[2] + f[1] * g[1];
    r3 = v3 + 19 * (f[4] * g[4]) + f[0] * g[3] + f[1] * g[2] + f[2] * g[1];
    r4 = v4 + f[0] * g[4] + f[1] * g[3] + f[2] * g[2] + f[3] * g[1];

    c0    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1 += carry;
    c1 = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    r2 += carry;
    c2 = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    r3 += carry;
    c3 = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    r4 += carry;
    carry  = (uint64_t) (r4 >> 51);
    c0   += 19 * carry;
    if ((c0 & ((uint64_t) (1) << 51)) !=0) 
    {
        c0 &= mask;
        c1++; 
    }
    
    if ((c1 & ((uint64_t) (1) << 51)) !=0) 
    {
        c1 &= mask;
        c2++; 
    }

    h[0] = c0;
    h[1] = c1;
    h[2] = c2;
    h[3] = c3;
    h[4] = r4 & mask;
}

It is worth mentioning that this essentially the same function, only the iterative increments are being made safer, enforcing no overlay flow.