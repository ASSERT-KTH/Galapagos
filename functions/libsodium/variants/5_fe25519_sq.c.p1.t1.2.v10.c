The proposed variant of the original functions breaks down the calculations further into individual steps. It still preserves the original function's essence and functionality, though:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t fstTemp[5], secTemp[8];
    uint64_t  result[5], carry;

    /* Apply casting as provided in the original code. */
    for(int i=0; i<5; ++i)
        fstTemp[i] = (uint128_t) f[i];

    /* Compute the derived operands just like in the original code */
    secTemp[0] = 2 * fstTemp[0];
    secTemp[1] = 2 * fstTemp[1];
    secTemp[2] = 38 * fstTemp[1];
    secTemp[3] = 38 * fstTemp[2];
    secTemp[4] = 38 * fstTemp[3];
    secTemp[5] = 19 * fstTemp[3];
    secTemp[6] = 19 * fstTemp[4];
    secTemp[7] = 2 * fstTemp[4];

    /* Computed squared values as described in the original function. */
    result[0] = fstTemp[0] * fstTemp[0] + secTemp[2] * fstTemp[4] + secTemp[3] * fstTemp[3];
    result[1] = secTemp[0] * fstTemp[1] + secTemp[3] * fstTemp[4] + secTemp[5] * fstTemp[2];
    result[2] = secTemp[0] * fstTemp[2] + fstTemp[1] * fstTemp[1] + secTemp[4] * fstTemp[4];
    result[3] = secTemp[0] * fstTemp[3] + secTemp[1] * fstTemp[2] + secTemp[6] * fstTemp[1];
    result[4] = secTemp[1] * fstTemp[3] + secTemp[7] * fstTemp[0] + fstTemp[2] * fstTemp[2];

    /* We apply a loop to reduce the redundancy from original code. */
    for(int i=0; i<5; ++i)
    {
        h[i]     = result[i] & mask;
        carry    = result[i] >> 51;

        if(i<4)
            result[i+1] += carry;
        else
            h[0] += 19 * carry;
        
        carry    = h[i] >> 51;
        h[i]    &= mask;

        if(i<4)
            h[i+1] += carry;
    }
}
