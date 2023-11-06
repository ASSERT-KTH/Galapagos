This is an optimized version of the same function. This version simply factors out common sub-expressions to reduce duplicate calculations, costing less execution time:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int i, j;
    int64_t hTmp[2 * 10];
    int64_t carry;

    for (i = 0; i < 2 * 10; i++)
        hTmp[i] = 0;

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            hTmp[i + j] += (int64_t)f[i] * g[j] * ((i + j) % 2 == 0 ? 1 : 19);

    for (i = 0; i < 10; i++) {
        carry = hTmp[i] >> 26;
        h[i] = (int32_t)(hTmp[i] - (carry << 26));
        hTmp[i + 1] += carry; 
    }

    carry = (hTmp[0] != h[0]) ? ((hTmp[0] - h[0]) >> 25) * 19 : 0;
    h[0] = (int32_t)(h[0] + carry);
    h[1] += (int32_t)carry;
}

This directly substitutes and adds all necessary pairwise products upfront (having distinctions for whether the degree of the resultant monomial is even or odd so as to properly apply the necessary multiplication by 19 for the off-diagonal terms). Then it applies the necessary normalization, incoporated within the carry procedure that ensure final values are in the normalized form (positive and less than 2^26 or 2^25). For h[0], it further takes into account that added multiples of p=2^255-19 might have been excessive, hence requires adjustment via h[0] += 19*carry and h[1] += carry.