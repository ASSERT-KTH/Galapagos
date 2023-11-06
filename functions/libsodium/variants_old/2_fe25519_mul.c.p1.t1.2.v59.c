fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0=0, r1=0, r2=0, r3=0, r4=0;
    uint128_t f0=0, f1=0, f2=0, f3=0, f4=0;
    uint128_t g0=0, g1=0, g2=0, g3=0, g4=0;
    uint128_t f_19[5] = {f[0] * 19ULL, f[1] * 19ULL, f[2] * 19ULL, f[3] * 19ULL, f[4] * 19ULL};
    uint64_t  result[5] = {0, 0, 0, 0, 0};
    uint64_t  carry = 0;

    for(int i=0; i<5; ++i) {
        f0 = (uint128_t) f[i];
        g0 = (uint128_t) g[i];

        r0 += f0 * g0 + f_19[i] * g[4] + f_19[(i + 1) % 5] * g[3] + f_19[(i + 2) % 5] * g[2] + f_19[(i + 3) % 5] * g[1];
        r1 += f0 * g[1] + f_19[i] * g[0] + f_19[(i + 1) % 5] * g[4] + f_19[(i + 2) % 5] * g[3] + f_19[(i + 3) % 5] * g[2];
        r2 += f0 * g[2] + f_19[i] * g[1] + f_19[(i + 1) % 5] * g[0] + f_19[(i + 2) % 5] * g[4] + f_19[(i + 3) % 5] * g[3];
        r3 += f0 * g[3] + f_19[i] * g[2] + f_19[(i + 1) % 5] * g[1] + f_19[(i + 2) % 5] * g[0] + f_19[(i + 3) % 5] * g[4];
        r4 += f0 * g[4] + f_19[i] * g[3] + f_19[(i + 1) % 5] * g[2] + f_19[(i + 2) % 5] * g[1] + f_19[(i + 3) % 5] * g[0];

        result[i]    = (uint64_t) r0 & mask;
        carry  = (uint64_t) (r0 >> 51);
        r1    += carry;
        result[(i + 1) % 5]    = (uint64_t) r1 & mask;
        carry  = (uint64_t) (r1 >> 51);
        r2    += carry;
        result[(i + 2) % 5]    = (uint64_t) r2 & mask;
        carry  = (uint64_t) (r2 >> 51);
        r3    += carry;
        result[(i + 3) % 5]    = (uint64_t) r3 & mask;

        carry  = (uint64_t) (r3 >> 51); 
        r4    += carry;
        result[(i + 4) % 5]    = (uint64_t) r4 & mask;

        carry  = (uint64_t) (r4 >> 51); 
        result[i]   += 19ULL * carry;
        carry  = result[i] >> 51;
        result[i]   &= mask;
        result[(i + 1) % 5]   += carry;

    }   

    h[0] = result[0];
    h[1] = result[1];
    h[2] = result[2];
    h[3] = result[3];
    h[4] = result[4];
}  
This version of the code operates on exactly the same principles as the original, it's just written differently.