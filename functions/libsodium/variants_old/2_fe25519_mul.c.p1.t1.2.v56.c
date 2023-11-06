
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t tst_mask = 0x7ffffffffffffULL;
    uint128_t temp_res[5] = {0};
    uint128_t temp_mul_terms[10] = {0};
    uint128_t f9g4, f8g3, f7g2, f6g1;
    uint64_t  item[5] = {0};
    uint64_t  overflow;
    int i;  
    
    for ( i = 0; i < 5; i++) {
        temp_mul_terms[i] = (uint128_t) f[i] * (uint128_t) g[i];
    }

    f9g4 = 19ULL * f[1] * (uint128_t) g[4];
    f8g3 = 19ULL * f[2] * (uint128_t) g[3];
    f7g2 = 19ULL * f[3] * (uint128_t) g[2];
    f6g1 = 19ULL * f[4] * (uint128_t) g[1];

    for ( i = 0; i < 5; i++) {
        temp_res[i] = temp_mul_terms[0];
        temp_res[(i + 4) % 5] += f9g4;
        temp_res[(i + 3) % 5] += f8g3;
        temp_res[(i + 2) % 5] += f7g2;
        temp_res[(i + 1) % 5] += f6g1;
    }

    for ( i = 0; i < 5; i++) {
        item[i]    = ((uint64_t) temp_res[i]) & tst_mask;
        overflow  = (uint64_t) (temp_res[i] >> 51);
        temp_res[(i + 1) % 5]     += overflow;
    }

    item[0] += 19ULL * overflow;
    overflow  = item[0] >> 51;
    item[0]   &= tst_mask;
    item[1] += overflow;
    overflow  = item[1] >> 51;
    item[1]   &= tst_mask;
    item[2] += overflow;

    for ( i = 0; i < 5; i++) {
        h[i] = item[i];
    }
}
