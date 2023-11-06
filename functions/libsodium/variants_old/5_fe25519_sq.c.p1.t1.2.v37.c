fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL; 
    
    uint128_t r[5], f_tmp[5], mul_res[7];
    uint64_t carry;

    for(int i = 0; i<5; i++) {
        f_tmp[i] = ((uint128_t)f[i]);
    }

    mul_res[0] = f_tmp[0] << 1;
    mul_res[1] = f_tmp[1] << 1;

    mul_res[2] = 38ULL * f_tmp[1];
    mul_res[3] = 38ULL * f_tmp[2];
    mul_res[4] = 38ULL * f_tmp[3];

    mul_res[5] = 19ULL * f_tmp[3];
    mul_res[6] = 19ULL * f_tmp[4];

    r[0] =   f_tmp[0] * f_tmp[0] + mul_res[2] * f_tmp[4] + mul_res[3] * f_tmp[3];
    r[1] = mul_res[0] * f_tmp[1] + mul_res[3] * f_tmp[4] + mul_res[5] * f_tmp[3];
    r[2] = mul_res[0] * f_tmp[2] +  f_tmp[1] * f_tmp[1] + mul_res[4] * f_tmp[4];
    r[3] = mul_res[0] * f_tmp[3] +  mul_res[1] * f_tmp[2] + mul_res[6] * f_tmp[4];
    r[4] = mul_res[0] * f_tmp[4] +  mul_res[1] * f_tmp[3] +    f_tmp[2] * f_tmp[2];

    h[0] = ((uint64_t)r[0]) & mask; 
    carry  = (uint64_t) (r[0] >> 51);
    r[1] += carry;
    
    for(size_t i = 1; i < 5; ++i) { 
        h[i]  = ((uint64_t)r[i]) & mask; 
        carry = (uint64_t)(r[i] >> 51);
        if (i+1 < 5) {
            fillCarry(carry, &r[i+1]);
    	} 
        else {
        	h[0] += 19ULL * carry;
        } 
        
        h[i-1] += r[i-1] >> 51;
        h[i-1] &= mask; 
    }

    h[2] += h[1] >> 51;  
    h[1] &= mask;
}
