fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t arr_r[5], f_modified[5], g_modified[5];
    uint128_t arr_f_comp[4];
    uint64_t  arr_final[5];
    uint64_t  carry;

    for(int i=0; i<5; i++){
        f_modified[i] = (uint128_t) f[i];
        g_modified[i] = (uint128_t) g[i];
        if(i!=0){
            arr_f_comp[i-1] = 19ULL * f_modified[i];
        }
    }

    arr_r[0] = f_modified[0] * g_modified[0] + arr_f_comp[0] * g_modified[4] + arr_f_comp[1] * g_modified[3] + arr_f_comp[2] * g_modified[2] + arr_f_comp[3] * g_modified[1];
    arr_r[1] = f_modified[0] * g_modified[1] +    f_modified[1] * g_modified[0] + arr_f_comp[1] * g_modified[4] + arr_f_comp[2] * g_modified[3] + arr_f_comp[3] * g_modified[2];
    arr_r[2] = f_modified[0] * g_modified[2] +    f_modified[1] * g_modified[1] +    f_modified[2] * g_modified[0] + arr_f_comp[2] * g_modified[4] + arr_f_comp[3] * g_modified[3];
    arr_r[3] = f_modified[0] * g_modified[3] +    f_modified[1] * g_modified[2] +    f_modified[2] * g_modified[1] +    f_modified[3] * g_modified[0] + arr_f_comp[3] * g_modified[4];
    arr_r[4] = f_modified[0] * g_modified[4] +    f_modified[1] * g_modified[3] +    f_modified[2] * g_modified[2] +    f_modified[3] * g_modified[1] +    f_modified[4] * g_modified[0];

    for(int i=0; i<5; i++){
        arr_final[i]    = ((uint64_t) arr_r[i]) & mask;
        carry  = (uint64_t) (arr_r[i] >> 51);
        arr_r[(i+1)%5]    += carry;
        arr_final[(i+1)%5]    = ((uint64_t) arr_r[(i+1)%5]) & mask;
        carry  = (uint64_t) (arr_r[(i+1)%5] >> 51);
        arr_final[(i+2)%5]   += carry;
    }

    
    arr_final[0] += 19ULL * ((uint64_t) (arr_r[0] >> 51));
    arr_final[0] &= mask;

    for (int i = 0; i < 5; i++){
       h[i] = arr_final[i] += i<2 ? mask - (((uint64_t) (arr_final[i] >> 51)) << 51) : 0 ;
    }
}