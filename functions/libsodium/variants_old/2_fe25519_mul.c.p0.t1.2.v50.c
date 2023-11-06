fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_mapped[5], f19_mapped[5], g_mapped[5];
    uint64_t  r_under[5], carry;

    for(int i = 0; i<5; i++) {
        f_mapped[i] = (uint128_t) f[i];
        g_mapped[i] = (uint128_t) g[i];
        if(i != 0){
            f19_mapped[i] = 19ULL * f_mapped[i];
        }
    }

    r[0] = f_mapped[0] * g_mapped[0] + f19_mapped[1] * g_mapped[4] + f19_mapped[2] * g_mapped[3] +
           f19_mapped[3] * g_mapped[2] + f19_mapped[4] * g_mapped[1];
    r[1] = f_mapped[0] * g_mapped[1] + f_mapped[1] * g_mapped[0] + f19_mapped[2] * g_mapped[4] +
           f19_mapped[3] * g_mapped[3] + f19_mapped[4] * g_mapped[2];
    r[2] = f_mapped[0] * g_mapped[2] + f_mapped[1] * g_mapped[1] + f_mapped[2] * g_mapped[0] +
           f19_mapped[3] * g_mapped[4] + f19_mapped[4] * g_mapped[3];
    r[3] = f_mapped[0] * g_mapped[3] + f_mapped[1] * g_mapped[2] + f_mapped[2] * g_mapped[1] +
           f_mapped[3] * g_mapped[0] + f19_mapped[4] * g_mapped[4];
    r[4] = f_mapped[0] * g_mapped[4] + f_mapped[1] * g_mapped[3] + f_mapped[2] * g_mapped[2] +
           f_mapped[3] * g_mapped[1] + f_mapped[4] * g_mapped[0];

    for(int i=0; i<5; i++){
        r_under[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if(i != 4){
            r[i+1] += carry;
        }else{
            r_under[0] += 19ULL * carry;
        }
    }
    
    for(int i=0; i<3; i++){
        carry  = r_under[i] >> 51;
        r_under[i] &= mask;
        
        if(i+1 <= 4)
            r_under[i+1] += carry;
    }
    
    for(int i=0; i<5; i++){
        h[i] = r_under[i];
    }
}