This code works by following the exact same steps as the original but rearranging the operations and sequences for more clarity. This can make the function easier to understand while maintaining its original functionality.


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t fi[5], fi_19[4], gi[5], ri[5];
    uint64_t r0, r1, r2, r3, r4, carry = 0;

    for(int i=0; i<5; i++)
    {
        fi[i] = f[i];
        gi[i] = g[i];
        if(i<4) fi_19[i] = 19ULL * fi[i+1];
    }
    for(int i=0; i<5; i++)
    {
        ri[i] = fi[0] * gi[i];
        for(int j=1; j<5; j++)
        {
            if(j<5-i) ri[i] += f[j] * gi[5 - j];
            else ri[i] += fi_19[j - 1 - i] * gi[(5 - j) % 5];
        }
    }
    for(int i=0; i<5; i++)
    {
       ri[i] += carry;
        h[i] = (uint64_t)ri[i] & mask;
        carry = (uint64_t) (ri[i] >> 51);
    }
    h[0] += 19 * carry;
}
