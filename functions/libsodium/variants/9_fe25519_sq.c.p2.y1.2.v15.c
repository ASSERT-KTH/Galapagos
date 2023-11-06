void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fi[10], fi_2[10], fi38[5];
    int64_t fj[10], fj_2[10];
    for (int i = 0; i < 10; ++i)
    {
        fi[i] = f[i];
        if (i < 5) {fi38[i] = 38 * f[i];}
        fi_2[i] = 2 * fi[i];
    }

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            int64_t t = fi[i] * (int64_t) fi[j];
            if (i == j) fj[j] = t;
            else fj[i] = 2 * t;

            if ((i < 5) && (j < 5)) fj_2[i] = t * (int64_t) fi38[j];
            else fj_2[i] = fi_2[i] * (int64_t) fi[j];
        }
    }

    int64_t hh[10] = {
        fj[0] + fj_2[9], fj[1] + fj_2[8], fj[2] + fj_2[7],
        fj[3] + fj_2[6], fj[4] + fj_2[5], fj[5] + fj_2[4],
        fj[6] + fj_2[3], fj[7] + fj_2[2], fj[8] + fj_2[1], fj[9] + fj_2[0]
    };
    
    for (int i = 0; i < 9; ++i)
    {
        int64_t carry = (hh[i] + (int64_t)(1L << (25 - (i & 1)))) >> (26 - (i & 1));
        hh[i+1] += carry;
        hh[i] -= carry * ((uint64_t)19 << (25 - (i & 1)));
    }
      
    int64_t carry0 = (hh[9] + (int64_t)(1L << 24)) >> 25;
    hh[0] += carry0 * 19;
    hh[9] -= carry0 * ((uint64_t) 1L << 25);
    
    for (int i = 0; i < 10; ++i) {h[i] = (int32_t) (hh[i] % ((int64_t) 1 << (25 + (i & 1))));}
}