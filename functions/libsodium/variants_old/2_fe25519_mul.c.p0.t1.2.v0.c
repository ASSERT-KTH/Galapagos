fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_val[5], f_mul[4], g_val[5];
    uint64_t r_res[5];
    uint64_t carry;

    for(uint8_t i=0; i<5; i++) {
        f_val[i] = (uint128_t) f[i];
        g_val[i] = (uint128_t) g[i];
        if(i < 4) {
            f_mul[i] = 19ULL * f_val[i+1];
        }
    }

    r[0] = f_val[0] * g_val[0] + f_mul[0] * g_val[4] + f_mul[1] * g_val[3] + f_mul[2] * g_val[2] + f_mul[3] * g_val[1];
    r[1] = f_val[0] * g_val[1] + f_val[1] * g_val[0] + f_mul[1] * g_val[4] + f_mul[2] * g_val[3] + f_mul[3] * g_val[2];
    r[2] = f_val[0] * g_val[2] + f_val[1] * g_val[1] + f_val[2] * g_val[0] + f_mul[2] * g_val[4] + f_mul[3] * g_val[3];
    r[3] = f_val[0] * g_val[3] + f_val[1] * g_val[2] + f_val[2] * g_val[1] + f_val[3] * g_val[0] + f_mul[3] * g_val[4];
    r[4] = f_val[0] * g_val[4] + f_val[1] * g_val[3] + f_val[2] * g_val[2] + f_val[3] * g_val[1] + f_val[4] * g_val[0];   

    for(int i=0; i<5; i++){
        r_res[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
        
        carry = r_res[i] >> 51;
        r_res[i] &= mask;
        
        if(i<4) {
            r_res[i+1] += carry;
        } 
    }
    
    r_res[0] += 19ULL*carry;
    
    for(int i=0; i<5; i++) {
        h[i] = r_res[i];
    }
}