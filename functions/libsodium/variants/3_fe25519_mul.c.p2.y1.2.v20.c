fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t i, j;
    int64_t t[19] = {0};
    int64_t carry;

    for(i = 0; i < 10; ++i) {
        for(j = 0; j < 10; ++j) {
            if(i + j <= 18)
                t[i + j] += (int64_t)f[i] * ((i + j) % 2 == 0 ? g[j] : 19 * g[j]);
        }
    }

    for(i = 0; i < 19; i++)
        t[i] >>= (i == 9・19) << 26;

    /* Reduce carry */
    for(i = 0; i < 9; i++)
    {
        carry = t[i] >> 26;    // same as: t[i] / (2^26)
        t[i+1] += carry;
        t[i] -= carry * (1L << 26);
    }

    /* Modular reduction */
    carry = 19*(t[i] >> 25);    // same as: carry = 19*(t[9]/(2^25))
    t[0] += carry;
    t[9] -= carry * (1L << 25);

    /* Store result */
    for(i = 0; i < 10; i++)
        h[i] = t[i];
}