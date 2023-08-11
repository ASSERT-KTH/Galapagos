fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_mt[5];
    uint128_t g_mt[5];
    uint64_t  carry;

    for(int i=0; i<5; i++) {
        f_mt[i] = (uint128_t) f[i];
        g_mt[i] = (uint128_t) g[i];
    }

    f_mt[1] *= 19ULL; f_mt[2] *= 19ULL; f_mt[3] *= 19ULL; f_mt[4] *= 19ULL;

    r[0] = performCalculate(f_mt,g_mt,0, 4, 3, 2, 1);
    r[1] = performCalculate(f_mt,g_mt,1, 0, 4, 3, 2);
    r[2] = performCalculate(f_mt,g_mt,2, 1, 0, 4, 3);
    r[3] = performCalculate(f_mt,g_mt,3, 2, 1, 0, 4);
    r[4] = performCalculate(f_mt,g_mt,4, 3, 2, 1, 0);

    for(int i=0; i<5; i++) { 
        r[i]   += (i==0) ? 0 : ((uint64_t) (r[i-1] >> 51));
        h[i]    = ((uint64_t) r[i]) & mask;
    }

    carry  = h[4] >> 51;
    h[0] += 19ULL * carry;
    carry  = h[0] >> 51;
    h[0] &= mask;
    h[1] += carry;
    carry  = h[1] >> 51;
    h[1] &= mask;
    h[2] += carry;

}

uint128_t performCalculate(const uint96_t *f_mt,const uint96_t *g_mt, int f0_index ,int f1_index, int f2_index, int f3_index, int f4_index) {
    return f_mt[f0_index] * g_mt[0] + f_mt[f1_index] * g_mt[gi4_index] + 
                 f_mt[f2_index] * g_mt[gi3_index] + f_mt[f3_index] * g_mt[g2_index] + f_mt[fivar_index] * g_mt[1] ;
}