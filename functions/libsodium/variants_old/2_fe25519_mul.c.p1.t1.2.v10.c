const uint64_t mask = 0x7ffffffffffffULL;
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t temp_results[5] = {0};
    uint64_t r[] = {0, 0, 0, 0, 0, 0};
    uint64_t carry = 0;
    size_t i, tempCarryComputations[] = {0, 2, 3, 4, 1}, tempResultsComputations[] = {0, 4, 3, 2, 1};

    uint5 x19[5] = {
        g[0],
        19 * g[4],
        19 * g[3],
        19 * g[2],
        19 * g[1]
    };
    for (i=0; i < ((sizeof(temp_results) / sizeof(temp_results[0]))- 1); i++){
        temp_results[i] = f[i] * x19[i] + f[i+1] * x19[i+1] + f[tempResultsComputations[i]] * x19[tempResultsComputations[i]]
                          + f[tempResultsComputations[i]+1] * x19[i+2] + f[tempResultsComputations[i]+2] * g[i];
    }
    temp_results[4] = f[0] * g[4] + f[1] * g[3] + f[2] * g[2] + f[3] * g[1] + f[4] * g[0];

    for(i =0; i <((sizeof(r)/sizeof(r[0]))-2); i++)
    {
        r[i] = ((uint64_t) temp_results[i]) & mask;
        carry = (uint64_t) (temp_results[i] >> 51);
        temp_results[i +1] += carry;
    }

    r[4] = ((uint64_t) temp_results[4]) & mask;

    r[0] += 19 * ((temp_results[4]) >> 51);
    carry = r[0] >> 51;
    r[0] &= mask;

    for(i=1; i < (sizeof(r)/sizeof(r[0]) - 1); i++)
    {
        r[i] += carry;
        carry = r[i] >> 51;
        r[i] &= mask;
    }

    r[2] += carry;
    
    memcpy(h, &r, sizeof(0LL) * 5);
}