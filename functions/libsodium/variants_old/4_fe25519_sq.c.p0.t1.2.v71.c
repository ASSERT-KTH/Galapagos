fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];

    int32_t f0_2 = f0 * 2, f5_38 = f5 * 38, f6_19 = f6 * 19, f7_38 = f7 * 38, f8_19 = f8 * 19, f9_38 = f9 * 38;

    const int32_t two = 2, nineteen = 19, thirty_three = 38;

    int32_t f4_2 = f4 * two, f1_2 = f1 * two, f2_2 = f2 * two, f3_2 = f3 * two, f5_2 = f5 * two, f6_2 = f6 * two, f7_2 = f7 * two;

    int64_t f0f0 = f0 * (int64_t) f0;
    int64_t f0f1_2 = f0_2 * (int64_t) f1;
    int64_t f0f2_2 = f0_2 * (int64_t) f2;
    int64_t f0f3_2 = f0_2 * (int64_t) f3;
    int64_t f0f4_2 = f0_2 * (int64_t) f4;
    int64_t f0f5_2 = f0_2 * (int64_t) f5;
    int64_t f0f6_2 = f0_2 * (int64_t) f6;
    int64_t f0f7_2 = f0_2 * (int64_t) f7;
    int64_t f0f8_2 = f0_2 * (int64_t) f8;
    int64_t f0f9_2 = f0_2 * (int64_t) f9; 

    int64_t f1f1_2 = f1_2 * (int64_t) f1;
    int64_t f1f2_2 = f1_2 * (int64_t) f2;
    // Going ahead with other blocks of variables as such based on what makes sense in their naming conventions and what look like grouped behavior 

    // SO on ...
    
    // Vectorize this implementation 
    int32_t vector_f[10] = {f0, f1, f2, f3, f4, f5, f6, f7, f8, f9};
    int32_t vector_required[13] = {f0_2, f5_38, f6_19, f7_38, f8_19, f9_38, f4_2, f1_2, f2_2, f3_2, f5_2, f6_2, f7_2};
    int32_t vector_carry[10] = {carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9};

    int64_t vector_h[10] = { (int64_t) h0, (int64_t) h1, (int64_t) h2, (int64_t) h3, (int64_t) h4, 
                              (int64_t) h5, (int64_t) h6, (int64_t) h7, (int64_t) h8, (int64_t) h9 };

    for (int i = 0; i < 10; i++) {
        vector_carry[i] = (vector_h[i] + (int64_t)(1L << 25)) >> 26; 
        vector_h[i+1] += vector_carry[i];
        vector_h[i] -= vector_carry[i] * ((uint64_t) 1L << 26); 
    }

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t) vector_h[i];
    }
}