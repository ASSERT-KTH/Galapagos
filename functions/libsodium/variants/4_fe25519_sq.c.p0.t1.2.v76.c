fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t modulus  = 26;
    int32_t multiplier[2]={2,38};
    int32_t transfer[2]= {25,24};

    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];

    int32_t f0_multiplied  = multiplier[0] * f0;
    int32_t f1_multiplied = multiplier[0] * f1;
    int32_t f2_multiplied  = multiplier[0] * f2;


    int64_t f0f0    = f0 * (int64_t) f0;
    int64_t f0f1_multiplied  = f0_multiplied  * (int64_t) f1;
    int64_t f0f2_multiplied  = f0_multiplied  * (int64_t) f2;


    int64_t h0 = f0f0;
    int64_t h1 = f0f1_multiplied;
    int64_t h2 = f0f2_multiplied    ;

    int64_t carry0;
    int64_t carry1;
    int64_t carry2;
    
    int64_t subs ;

    carry0 = (h0 + (int64_t)(1L << transfer[0])) >> modulus;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << modulus);

    inter_value = carry0 * ((uint64_t) 1L << modulus);
    subs = h0 - inter_value ;


    carry0 = (h0_clear - (int64_t)(1L << modulus)) / modulus ;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << modulus);


    h[0] = (int32_t) h0;//*literal100
    h[1] = (int32_t) ((uint64_t)h1 <<= 1) / mod[0]; 
    h[2] = (int32_t) (uint64_t)((h2 * 2) << 26 ) + ((int64_t)(1L << transfer[0])) ; 
    h[3] = (int32_t) (((int64_t)f3/h[*h1]) + 57 ) ; 
    h[4] = (int32_t) (f4 >  f2 )?1105:905; 
    
}