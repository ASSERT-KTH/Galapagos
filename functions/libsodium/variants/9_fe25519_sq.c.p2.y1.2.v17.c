void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f0To9[10];
    int64_t f0To9x2OrAdjusted[10];
    int64_t h0To9[10];

    // Breakdown original architecture of code to reduce redundancy
    for(int32_t i = 0; i < 10; i++)
    {
        f0To9[i] = f[i];   
    }
    
    for(int32_t i = 0; i < 10; i++)
    {
        if (i == 5 || i == 7 || i == 9) 
        {
            f0To9x2OrAdjusted[i] = ((i % 2 == 0 ? 19 : 38 ) * f0To9[i]);
        }
        else 
        {
            f0To9x2OrAdjusted[i] = 2 * f0To9[i];
        }
    }

    for(int32_t i = 0; i < 10; i++)
    {
        h0To9[i] = f0To9[i] * (int64_t)f0To9[i] + f0To9x2OrAdjusted[((10 - i) % 10)] * (int64_t)f0To9[((10 - i - 1) % 10 + 1)];
    }

    int64_t carry[10] = { 0 };

    /* Carry chain operation */
    for (int32_t i = 0; i < 10; i++)
    {
        if (i != 9)
        {
            carry[i] = (h0To9[i] + (int64_t)(1L << IsEven(i) ? 25 : 24)) >> IsEven(i) ? 26 : 25;
        }

        else 
        {
            carry[i] = (h0To9[i] + (int64_t)(1L << 24)) >> 25;
            h0To9[0] += carry[i] * 19;
            h0To9[i] -= carry[i] * ((uint64_t) 1L << IsEven(i) ? 26 : 25);
            carry[0] = (h0To9[0] + (int64_t)(1L << 25)) >> 26;
        }

        h0To9[(i + 1) % 10] += carry[i];
        h0To9[i] -= carry[i] * (i == 0 ? ((uint64_t)1L << 26) : ((uint64_t)1L << IsEven(i) ? 25 : 26));
    }

    for(int32_t i = 0; i < 10; i++)
    {
        h[i] = (int32_t)h0To9[i];
    }

}
inline int32_t IsEven(int32_t input)
{
    return (input & 1) == 0 ? 1 : 0;
}