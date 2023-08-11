fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f1_19, f2_19, f3_19, f4_19, g_tmp[5];
    uint64_t  carry;
    
    for(int i=0; i<5;i++){
        r[i] =  (uint128_t) f[i];
        g_tmp[i] = (uint128_t) g[i];
        if(i>0){
           r[i]*=19ULL;
        }
    }

    f1_19 = r[1];
    f2_19 = r[2];
    f3_19 = r[3];
    f4_19 = r[4];
   
    r[0] = r[0] * g_tmp[0] + f1_19 * g_tmp[4] + f2_19 * g_tmp[3] + f3_19 * g_tmp[2] + f4_19 * g_tmp[1];
    r[1] = r[0] * g_tmp[1] +    r[1] * g_tmp[0] + f2_19 * g_tmp[4] + f3_19 * g_tmp[3] + f4_19 * g_tmp[2];
    r[2] = r[0] * g_tmp[2] +    r[1] * g_tmp[1] +    r[2] * g_tmp[0] + f3_19 * g_tmp[4] + f4_19 * g_tmp[3];
    r[3] = r[0] * g_tmp[3] +    r[1] * g_tmp[2] +    r[2] * g_tmp[1] +    r[3] * g_tmp[0] + f4_19 * g_tmp[4];
    r[4] = r[0] * g_tmp[4] +    r[1] * g_tmp[3] +    r[2] * g_tmp[2] +    r[3] * g_tmp[1] +    r[4] * g_tmp[0];

    for(int i=0; i<5;i++){
        if(i!=0){
            carry =  (uint64_t) (r[i-1] >> 51);
            r[i] += carry;
       
        }
        h[i]= ((uint64_t)r[i]) & mask;
        
        if(i<4){
            carry  = (uint64_t) (r[i] >> 51);
            h[0] += 19ULL * carry;  
        }
    }

    carry =   h[0] >> 51;
    h[0] &= mask;
    h[1] +=   carry;
    carry =   h[1] >> 51;
    h[1] &= mask;
    h[2] += carry;

}