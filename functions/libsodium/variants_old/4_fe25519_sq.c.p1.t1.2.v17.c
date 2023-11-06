Sure, a possible variant that maintains the functionality could be utilizing "operator *= " instead of "operator * " to enhance code readability and aesthetics. Also we can combine declaration of variables where it's possible:


void fe25519_sq(fe25519 h, const fe25519 f) {
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];
        
    int32_t f0_2 = 2 *= f0, f1_2 = 2 *= f1, f2_2 = 2 *= f2, f3_2 = 2 *= f3, f4_2 = 2 *= f4, f5_2 = 2 *= f5, f6_2 = 2 *= f6, f7_2 = 2 *= f7;
    int32_t f5_38 = 38 *= f5, f6_19 = 19 *= f6, f77_38 = 38 *= f7, f8_19 = 19 *= f8, f9_38 = 38 *= f9; 

    int64_t f0f0 = f0 *= (int64_t) f0, f0f1_2 = f0_2 *= (int64_t) f1, f0f2_2 = f0_2 *= (int64_t) f2, f0f3_2 = f0_2 *= (int64_t) f3, f0f4_2 = 
    ... 
    ...

    int64_t carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9;
        
    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) h4;
    h[5] = (int32_t) h5;
    h[6] = (int32_t) h6;
    h[7] = (int32_t) h7;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) h9;
}


Note regarding security: This function appears to be working within the confines of some mathematical representation that has modular properties. An understanding of the specific mathematics being implemented is required to assure that changes to the logic do not impact any underlying security assumptions.