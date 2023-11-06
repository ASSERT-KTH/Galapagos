fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL; 
    uint128_t r[5]; 
    uint128_t f_cast[5];
    uint128_t f_mult[9];
    uint64_t r_final[5]; 
    uint64_t carry;

    for (int i = 0; i < 5; i++)
    {
        f_cast[i] = (uint128_t)f[i];
    }

    f_mult[0] = f_cast[0] << 1;
    f_mult[1] = f_cast[1] << 1;
    
    f_mult[2] = 38ULL * f_cast[1];
    f_mult[3] = 38ULL * f_cast[2];
    f_mult[4] = 38ULL * f_cast[3];

    f_mult[5] = 19ULL * f_cast[3];
    f_mult[6] = 19ULL * f_cast[4];

    r[0] =  f_cast[0] * f_cast[0] + f_mult[2] * f_cast[4] + f_mult[3] * f_cast[3];
    r[1] = f_mult[0] * f_cast[1] + f_mult[3] * f_cast[4] + f_mult[5] * f_cast[3];
    r[2] = f_mult[0] * f_cast[2] + f_cast[1] * f_cast[1] + f_mult[4] * f_cast[4];
    r[3] = f_mult[0] * f_cast[3] + f_mult[1] * f_cast[2] + f_mult[6] * f_cast[4];
    r[4] = f_mult[0] * f_cast[4] + f_mult[1] * f_cast[3] + f_cast[2] * f_cast[2];

    for (int i = 0; i < 5; i++)
    {
        r_final[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        
        if(i<4)
        {
            r[i+1] += carry;
        }
        
        else
        {
            r_final[0] += 19ULL * carry;
            carry = r_final[0] >> 51;
            r_final[0] &= mask;
            r_final[1] += carry;
            carry  = r_final[1] >> 51;
            r_final[1] &= mask;
            r_final[2] += carry;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        h[i] = r_final[i];
    }
}