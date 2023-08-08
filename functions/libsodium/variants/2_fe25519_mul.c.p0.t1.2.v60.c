
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_vals[5], g_vals[5], weighed_f[4];
    uint64_t  r_final[5], carry;

    for(int i=0; i<5; i++){
        f_vals[i] = (uint128_t) f[i];
        g_vals[i] = (uint128_t) g[i];
    }

    for(int i=1; i<5; i++){
        weighed_f[i-1] = 19ULL * f_vals[i];
    }

    r[0] = f_vals[0] * g_vals[0] + weighed_f[3] * g_vals[4] + weighed_f[1] * g_vals[2] + weighed_f[2] * g_vals[3] + weighed_f[0] * g_vals[1];
    r[1] = f_vals[0] * g_vals[1] +  f_vals[1] * g_vals[0] + weighed_f[1] * g_vals[3] + weighed_f[2] * g_vals[4] + weighed_f[0] * g_vals[2];
    r[2] = f_vals[0] * g_vals[2] +  f_vals[1] * g_vals[1] +  f_vals[2] * g_vals[0] + weighed_f[2] * g_vals[1] + weighed_f[0] * g_vals[3];
    r[3] = f_vals[0] * g_vals[3] +  f_vals[1] * g_vals[2] +  f_vals[2] * g_vals[1] +  f_vals[3] * g_vals[0] + weighed_f[0] * g_vals[4];
    r[4] = f_vals[0] * g_vals[4] +  f_vals[1] * g_vals[3] +  f_vals[2] * g_vals[2] +  f_vals[3] * g_vals[1] +  f_vals[4] * g_vals[0];

    for(int j=0; j<5; j++){
        r_final[ j] = ((uint64_t) r[j]) & mask;
        carry       = (uint64_t) (r[j] >> 51);
        r[(j+1)%5] += carry;
        r_final[j] += 19ULL * (j == 4 ? carry : 0);
        carry       = r_final[j] >> 51;
        r_final[j] &= mask;
        r_final[(j+1)%5] += carry;
    }

    for(int k=0; k<5; k++)
        h[k] = r_final[k];
}
