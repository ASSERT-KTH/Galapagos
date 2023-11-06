void fe25519_sq(fe25519 h, const fe25519 f)
{
    uint64_t filter = 0x7ffffffffffffULL;
    uint64_t carry;

    uint128_t  f_values[5];
    uint64_t  shifted_f_values[5];
    uint128_t  multiplied_f_values[5];
    uint128_t  r_values[5];
    uint64_t  shifted_r_values[5];

    for(int i = 0; i < 5; i++){
        f_values[i] = (uint128_t) f[i];  
    }
    
    for(int i = 0; i < 2; i++){
        shifted_f_values[i] = f_values[i] << 1;    
    }

    for(int i = 1; i < 4; i++){
        multiplied_f_values[i-1] = 38ULL * f_values[i];
        if(i > 1){
            multiplied_f_values[i] = 19ULL * f_values[i];
        }
    }
    multiplied_f_values[4] = 19ULL * f_values[4];

    r_values[0] =   f_values[0] * f_values[0] + multiplied_f_values[0] * f_values[4] + multiplied_f_values[1] * f_values[3];
    r_values[1] = shifted_f_values[0] * f_values[1] + multiplied_f_values[1] * f_values[4] + multiplied_f_values[2] * f_values[3];
    r_values[2] = shifted_f_values[0] * f_values[2] +                 f_values[1] * f_values[1] +    multiplied_f_values[2] * f_values[4];
    r_values[3] =   shifted_f_values[0] * f_values[3] + shifted_f_values[1] * f_values[2] +     multiplied_f_values[4] * f_values[4];
    r_values[4] = shifted_f_values[0] * f_values[4] + shifted_f_values[1] * f_values[3] +       f_values[2] * f_values[2];

    for(int i = 0; i < 5; i++){
        if(i > 0){
            r_values[i] += carry;
        }
        shifted_r_values[i] = ((uint64_t) r_values[i]) & filter;
        carry = (uint64_t) (r_values[i] >> 51);
    }

    for(int i = 0; i < 3; i++){
        shifted_r_values[i] += 19ULL *carry;
        carry = shifted_r_values[i] >> 51;
        shifted_r_values[i] &= filter;
        shifted_r_values[i+1] += carry;

        h[i] = shifted_r_values[i];
    }

    h[3] = shifted_r_values[3];
    h[4] = shifted_r_values[4];
}