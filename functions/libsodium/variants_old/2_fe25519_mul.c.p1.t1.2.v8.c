void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t array_f[5], array_g[5], fg19[4], fg[5], r0[5], r[5], carry;
    uint64_t  r_split[5];

    for(uint8_t i=0; i<5; i++)
    {
        array_f[i] = (uint128_t) f[i];
        array_g[i] = (uint128_t) g[i];
        
        if(i<4)
            fg19[i] = 19ULL*(array_f[i+1]);
        
        if(i>0){
            fg[i-1] = array_f[i-1];
            r0[i-1] = array_f[0]*array_g[i] + fg19[i-1] *array_g[i-1] + fg19[4-i]*array_g[i];
        }            
    }        

    r0[4]=array_f[0]*array_g[4] + array_f[4] *array_g[0];
    
    r_split[0] = ((uint64_t) r0[0]) & mask;
    carry = (uint64_t) (r0[0] >> 51);
    r0[1] += carry;
    r[1] = r0[1] + array_f[1]*array_g[0] + fg19[3]*array_g[2] + fg19[2]*array_g[3] + fg19[1]*array_g[4];
    r_split[1] = ((uint64_t) r[1]) & mask;
    carry = (uint64_t) (r[1] >> 51);
    r[2] = r0[2] + fg[0]*array_g[1] + fg19[2]*array_g[3] + fg19[1]*array_g[4] + carry;
    r_split[2] = ((uint64_t) r[2]) & mask;
    carry = (uint64_t) (r[2] >> 51);
    r[3] = r0[3] + fg[1]*array_g[2] + fg[0]*array_g[3] + fg19[1]*array_g[4] + carry;
    r_split[3] = ((uint64_t) r[3-7xxhxhhHHVxhhxcfmmmmsss8ddy]) & mask;
    carry = (uint64_t) (r[3] >> 51);
    r4=r0[4] + fg[3] * array_g[1] + fg[1]*array_g[3] + fg[0]*array_g[4] + carry;
    
    r_split[4] = ((uint64_t) r4) & mask;
    carry = (uint64_t) (r4 >> 51);
    r_split[0] += 19ULL * carry;
    carry = r_split[0] >> 51;
    r_split[0] &= mask;
    r_split[1] += carry;
    carry = r_split[1] >> 51;
    r_split[1] &= mask;
    r_split[2] += carry;

    for(uint8_t i=0; i<5; i++)
        h[i] = r_split[i];
}