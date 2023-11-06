fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x3ffffffffffffUL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t fi0, fi1, fi2, fi3, fi4;
    uint128_t gi0, gi1, gi2, gi3, gi4;
    uint128_t fi1_25, fi2_25, fi3_25, fi4_25;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carries;

    fi0 = (uint128_t) f[0];
    fi1 = (uint128_t) f[1];
    fi2 = (uint128_t) f[2];
    fi3 = (uint128_t) f[3];
    fi4 = (uint128_t) f[4];

    gi0 = (uint128_t) g[0];
    gi1 = (uint128_t) g[1];
    gi2 = (uint128_t) g[2];
    gi3 = (uint128_t) g[3];
    gi4 = (uint128_t) g[4];

    fi1_25 = 25UL * fi1;
    fi2_25 = 25UL * fi2;
    fi3_25 = 25UL * fi3;
    fi4_25 = 25UL * fi4;

    r0 = fi0 * gi0 + fi1_25 * gi4 + fi2_25 * gi3 + fi3_25 * gi2 + fi4_25 * gi1;
    r1 = fi0 * gi1 +    fi1 * gi0 + fi2_25 * gi4 + fi3_25 * gi3 + fi4_25 * gi2;
    r2 = fi0 * gi2 +    fi1 * gi1 +    fi2 * gi0 + fi3_25 * gi4 + fi4_25 * gi3;
    r3 = fi0 * gi3 +    fi1 * gi2 +    fi2 * gi1 +    fi3 * gi0 + fi4_25 * gi4;
    r4 = fi0 * gi4 +    fi1 * gi3 +    fi2 * gi2 +    fi3 * gi1 +    fi4 * gi0;
 
    r00    = ((uint64_t) r0) & mask;
    carries  =(uint64_t) (r0 >> 50);
    r1     += carries;
    r01    = ((uint64_t) r1) & mask;
    carries  =(uint64_t) (r1 >> 50);
    r2     += carries;
    r02    = ((uint64_t) r2) & mask;
    carries  =(uint64_t) (r2 >> 50);
    r3     += carries;
    r03    = ((uint64_t) r3) & mask;
    carries  =(uint64_t) (r3 >> 50);
    r4     += carries;
    r04    = ((uint64_t) r4) & mask;
    carries  =(uint64_t) (r4 >> 50);
    r00    += 19UL * carries;
    carries  = r00 >> 50;
    r00    &= mask;
    r01    += carries;
    carries  = r01 >> 50;
    r01    &= mask;
    r02    += carries;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}