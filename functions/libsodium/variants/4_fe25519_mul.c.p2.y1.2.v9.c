fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t rg0, rg1, rg2, rg3, rg4;
    uint128_t rf[5];
    uint128_t gf[5];
    uint128_t f19[4];
    uint64_t  r[5];
    uint64_t  carry;
    int i;

    for(i=0; i<5; i++){
	rf[i] = (uint128_t) f[i];
	gf[i] = (uint128_t) g[i];
    }

    for(i=0; i<4; i++) 
	f19[i] = 19 * rf[i+1];

    rg0 = rf[0] * gf[0] + f19[0] * gf[4] + f19[1] * gf[3] + f19[2] * gf[2] + f19[3] * gf[1];
    rg1 = rf[0] * gf[1] +   rf[1] * gf[0] + f19[1] * gf[4] + f19[2] * gf[3] + f19[3] * gf[2];
    rg2 = rf[0] * gf[2] +   rf[1] * gf[1] +   rf[2] * gf[0] + f19[2] * gf[4] + f19[3] * gf[3];
    rg3 = rf[0] * gf[3] +   rf[1] * gf[2] +   rf[2] * gf[1] +   rf[3] * gf[0] + f19[3] * gf[4];
    rg4 = rf[0] * gf[4] +   rf[1] * gf[3] +   rf[2] * gf[2] +   rf[3] * gf[1] +   rf[4] * gf[0];

    r[0]    = ((uint64_t) rg0) & mask;
    carry  = (uint64_t) (rg0 >> 51);
    rg1   += carry;
    r[1]    = ((uint64_t) rg1) & mask;
    carry  = (uint64_t) (rg1 >> 51);
    rg2   += carry;
    r[2]    = ((uint64_t) rg2) & mask;
    carry  = (uint64_t) (rg2 >> 51);
    rg3   += carry;
    r[3]    = ((uint64_t) rg3) & mask;
    carry  = (uint64_t) (rg3 >> 51);
    rg4   += carry;
    r[4]    = ((uint64_t) rg4) & mask;
    carry  = (uint64_t) (rg4 >> 51);
    r[0]   += 19 * carry;
    carry  = r[0] >> 51;
    r[0]   &= mask;
    r[1]   += carry;
    carry  = r[1] >> 51;
    r[1]   &= mask;
    r[2]   += carry;

    for(i=0; i<5; i++)
      h[i] = r[i];
}