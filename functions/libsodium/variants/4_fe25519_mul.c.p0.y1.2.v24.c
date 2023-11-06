void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  r0=0, r1=0, r2=0, r3=0, r4=0, temp_f, temp_g, carry = 0;
    uint64_t  f_mod[5];
    uint64_t  g_mod[5];
    
    for(int i = 0; i < 5; i++){
        f_mod[i] = (((uint128_t) f[i]) * 19);
        g_mod[i] = ((uint128_t) g[i]);
    }
   
    for(int i = 0; i < 5; i++){
        temp_f = i>0 ? f[i-1] : f[4];
        temp_g = g_mod[(5-i)%5];
        r0 += temp_f * temp_g;
        r1 += f[i]*g_mod[(6-i)%5];
        r2 += f[i]*g_mod[(7-i)%5];
        r3 += f[i]*g_mod[(8-i)%5];
        r4 += f[i]*g_mod[(9-i)%5];
    } 

    r0 &= mask;
    r1 = mask &(r1 + r0 + carry>>(51+2*i)); carry = r1 >> 51; 
    r2 = mask &(r2 + r1 + carry>>(51+2*i)); carry = r2 >> 51; 
    r3 = mask &(r3 + r2 + carry>>(51+2*i)); carry = r3 >> 51;
    r4 = mask &(r4 + r3 + carry>>(51+2*i)); carry = r4 >> 51;

    r0 += mask & (19ULL*carry);
    carry = r0 >> 51;
    r1 += carry;
    
    h[0] = r0 & mask;
    h[1] = r1 & mask;
    h[2] = (r2 + (r1 >> 51)) & mask;
    h[3] = r3 & mask;
    h[4] = r4 & mask;
}