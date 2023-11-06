void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4, res[5];
    uint128_t factors1[5], factors2[5], factors1_correlation[5];
    uint64_t result_val[5], carry;
    int i;

    for(i = 0; i < 5; i++)
    {
        factors1[i] = (uint128_t) f[i];
        factors2[i] = (uint128_t) g[i];
    }

    factors1_correlation[0] = 1ULL * factors1[0];
    factors1_correlation[1] = 19ULL * factors1[1];
    factors1_correlation[2] = 19ULL * factors1[2];
    factors1_correlation[3] = 19ULL * factors1[3];
    factors1_correlation[4] = 19ULL * factors1[4];

    r0 = factors1_correlation[0] * factors2[0] + factors1_correlation[1] * factors2[4] + factors1_correlation[2] * factors2[3] + factors1_correlation[3] * factors2[2] + factors1_correlation[4] * factors2[1];
    r1 = factors1_correlation[0] * factors2[1] + factors1_correlation[1] * factors2[0] + factors1_correlation[2] * factors2[4] + factors1_correlation[3] * factors2[3] + factors1_correlation[4] * factors2[2];
    r2 = factors1_correlation[0] * factors2[2] + factors1_correlation[1] * factors2[1] + factors1_correlation[2] * factors2[0] + factors1_correlation[3] * factors2[4] + factors1_correlation[4] * factors2[3];
    r3 = factors1_correlation[0] * factors2[3] + factors1_correlation[1] * factors2[2] + factors1_correlation[2] * factors2[1] + factors1_correlation[3] * factors2[0] + factors1_correlation[4] * factors2[4];
    r4 = factors1_correlation[0] * factors2[4] + factors1_correlation[1] * factors2[3] + factors1_correlation[2] * factors2[2] + factors1_correlation[3] * factors2[1] + factors1_correlation[4] * factors2[0];

    res[0] = r0;
    res[1] = r1;
    res[2] = r2;
    res[3] = r3;
    res[4] = r4;

    for (i = 0; i < 5; i++)
    {
        result_val[i] = ((uint64_t)res[i]) & mask;
        carry = (uint64_t)(res[i] >> 51);
        if(i < 4)
        {
            res[i+1] += carry;
        }
        else
        {
            result_val[0] += 19 * carry;
        }
        
    carry = result_val[i] >> 51;
    result_val[i] &= mask;

    }

    carry = result_val[0] >> 51;
    result_val[0] &= mask;
    result_val[1] += carry;

    for(i = 0; i < 5; i++)
    {
        h[i] = result_val[i];
    }
}