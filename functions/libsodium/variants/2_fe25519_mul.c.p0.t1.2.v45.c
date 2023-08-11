fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t fval[5], gval[5], fx19[4];

    for(int i=0; i<5; i++)
    {
      fval[i] = (uint128_t) f[i];
      gval[i] = (uint128_t) g[i];
    }   

    for(int i=1; i<5; i++)
      fx19[i-1] = 19ULL * fval[i];

    r0 = fval[0] * gval[0] + fx19[0] * gval[4] + fx19[1] * gval[3] + fx19[2] * gval[2] + fx19[3] * gval[1];
    r1 = fval[0] * gval[1] + fval[1] * gval[0] + fx19[1] * gval[4] + fx19[2] * gval[3] +    fx19[3] * gval[2];
    r2 = fval[0] * gval[2] + fval[1] * gval[1] + fval[2] * gval[0] + fx19[2] * gval[4] +    fx19[3] * gval[3];
    r3 = fval[0] * gval[3] + fval[1] * gval[2] + fval[2] * gval[1] + fval[3] * gval[0] + fx19[3] * gval[4];
    r4 = fval[0] * gval[4] + fval[1] * gval[3] + fval[2] * gval[2] + fval[3] * gval[1] + fval[4] * gval[0];

    uint64_t rvalues[5] = {(uint64_t) r0, (uint64_t) r1, (uint64_t) r2, (uint64_t) r3, (uint64_t) r4};
    uint64_t carry;

    for(int i=0; i<5; i++)
    {
        rvalues[i] &= mask;
        carry = (uint64_t) (rvalues[i] >> 51);
        if (i != 4) rvalues[i+1] += carry;
    }

    rvalues[0] += 19ULL * carry;
    carry  = rvalues[0] >> 51;
    rvalues[0] &= mask;
    rvalues[1] += carry;
    carry  = rvalues[1] >> 51;
    rvalues[1] &= mask;
    rvalues[2] += carry;

    for(int i=0; i<5; i++)
      h[i] = rvalues[i];
}