Here is a variant of the function that maintains the same functionality but changes some aspects of the original implementation, mainly the order and arrangement of operators:

 
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
    {
        const uint64_t mask = 0x7ffffffffffffULL;
        uint128_t r0, r1, r2, r3, r4;
        uint128_t f0, f1, f2, f3, f4;
        uint128_t f1_19, f2_19, f3_19, f4_19;
        uint128_t g0, g1, g2, g3, g4;
        uint64_t  r00, r01, r02, r03, r04;
        uint64_t  carry;

        f0 = f[0];
        g0 = g[0];
        r0 = f0 * g0;

        f1 = f[1];
        g1 = g[1];
        f1_19 = 19 * f1;
        r0 += f1_19 * g[4];
        r1 = f0 * g1 + f1 * g0;

        f2 = f[2];
        g2 = g[2];
        f2_19 = f2 * 19;
        r0 += f2_19 * g3;
        r1 += f2_19 * g4;
        r2 = f0 * g2 + f1 * g1 +   f2 * g0;

        f3 = f[3];
        g3 = g[3];
        f3_19 = 19 * f3;
        r0 += f3_19 * g2;
        r1 += f3_19 * g3;
        r2 += f3_19 * g4; 
        r3 = f0 * g3 + f1 * g2 +   f2 * g1 +   f3 * g0;

        f4 = f[4];
        g4 = g[4];
        f4_19 = 19 * f4;
        r0 += f4_19 * g1;
        r1 += f4_19 * g2;
        r2 += f4_19 * g3;
        r3 += f4_19 * g4;
        r4 = f0 * g4 + f1 * g3 +   f2 * g2 +   f3 * g1 +   f4 * g0;

        r00    = ((uint64_t) r0) & mask;
        carry  = (uint64_t) (r0 >> 51);
        r1    += carry;
        r01    = ((uint64_t) r1) & mask;
        r2    += (carry  = (uint64_t) (r1 >> 51));
        r02    = ((uint64_t) r2) & mask;
        r3    += (carry  = (uint64_t) (r2 >> 51));
        r03    = ((uint64_t) r3) & mask;
        r4    += (carry  = (uint64_t) (r3 >> 51));
        r04    = ((uint64_t) r4) & mask;
        r00   += (carry  = (uint64_t) (r4 >> 51)) * 19;
        r01   += (carry  = r00 >> 51);
        r02   += (carry  = r01 >> 51);
        r00   &= mask;
        r01   &= mask;

        h[0] = r00;
        h[1] = r01;
        h[2] = r02;
        h[3] = r03;
        h[4] = r04;
    }
