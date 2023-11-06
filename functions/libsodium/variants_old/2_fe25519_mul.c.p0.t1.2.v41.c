fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t fe0, fe1, fe2, fe3, fe4;
    uint128_t fe1_19, fe2_19, fe3_19, fe4_19;
    uint128_t ge0, ge1, ge2, ge3, ge4;
    uint64_t  rh0, rh1, rh2, rh3, rh4;
    uint64_t over;

    fe0 = (uint128_t) f[0];
    fe1 = (uint128_t) f[1];
    fe2 = (uint128_t) f[2];
    fe3 = (uint128_t) f[3];
    fe4 = (uint128_t) f[4];

    ge0 = (uint128_t) g[0];
    ge1 = (uint128_t) g[1];
    ge2 = (uint128_t) g[2];
    ge3 = (uint128_t) g[3];
    ge4 = (uint128_t) g[4];

    fe1_19 = 19ULL * fe1;
    fe2_19 = 19ULL * fe2;
    fe3_19 = 19ULL * fe3;
    fe4_19 = 19ULL * fe4;

    rh0 = fe0 * ge0 + fe1_19 * ge4 + fe2_19 * ge3 + fe3_19 * ge2 + fe4_19 * ge1;
    rh1 = fe0 * ge1 +       fe1 * ge0 + fe2_19 * ge4 + fe3_19 * ge3 + fe4_19 * ge2;
    rh2 = fe0 * ge2 +       fe1 * ge1 +       fe2 * ge0 + fe3_19 * ge4 + fe4_19 * ge3;
    rh3 = fe0 * ge3 +       fe1 * ge2 +       fe2 * ge1 +       fe3 * ge0 + fe4_19 * ge4;
    rh4 = fe0 * ge4 +       fe1 * ge3 +       fe2 * ge2 +       fe3 * ge1 +        fe4 * ge0;

    rh0  = ((uint64_t) rh0) & mask;
    over = (uint64_t) (rh0 >> 51);
    rh1  += over;
    rh1  = ((uint64_t) rh1) & mask; 
    over = (uint64_t) (rh1 >> 51);
    rh2  += over;
    rh2  = ((uint64_t) rh2) & mask;
    over = (uint64_t) (rh2 >> 51);
    rh3  += over;
    rh3  = ((uint64_t) rh3) & mask; 
    over = (uint64_t) (rh3 >> 51);
    rh4  += over;
    rh4  = ((uint64_t) rh4) & mask; 
    over = (uint64_t) (rh4 >> 51);
    rh0 += 19ULL * over;
    over = rh0 >> 51;
    rh0 &= mask; 
    rh1 += over;
    over = rh1 >> 51;
    rh1 &= mask;
    rh2 += over;
 
    h[0] = rh0;
    h[1] = rh1;
    h[2] = rh2;
    h[3] = rh3;
    h[4] = rh4;
}