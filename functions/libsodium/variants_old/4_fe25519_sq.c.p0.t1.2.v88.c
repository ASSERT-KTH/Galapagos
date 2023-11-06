fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;

    int32_t f_38[5] = {38 * f5, 19 * f6, 38 * f7, 19 * f8, 38 * f9};

    // int64 is converted to long long for cross-platform compatibility
    long long int prod[45];
    prod[0] = f0 * (long long) f0;
    prod[1] = f0_2 * (long long) f1;
    prod[2] = f0_2 * (long long) f2;
    prod[3] = f0_2 * (long long) f3;
    prod[4] = f0_2 * (long long) f4;

    prod[10] = f1_2 * (long long) f1;
    prod[11] = f1_2 * (long long) f2;
    prod[12] = f1_2 * (long long) f3_2;
    prod[13] = f1_2 * (long long) f4;
  
    for(int I=0; I<5; ++I) {
        prod[5+I*5] = f0_2 * (long long) f5_2;
        prod[15+I*6] = f1_2 * (long long) f_38[I];
        prod[20+I*5] = f2 * (long long) f_38[I * 2 % 5];
        prod[25+I*4] = f3_2 * (long long) f_38[I * 3 % 5];
    }
     
    prod[34] = f4 * (long long) f01;
    prod[35] = f8 * (long long) f_38[3];
    prod[36] = f9 * (long long) f_38[4];

    for(int I=0; I<10; ++I) {
        long long carry= (prod[I*3] + (long long)(1L << ((I&1)?24:25))) >> ((I&1)?25:26);

        prod[I*3+1] += carry;
        prod[I*3] -= carry * ((unsigned long)1L << ((I&1)?25:26));
    }

    carry9 = (h9 + (long long)(1L << 24)) >> 25;
    h0 += carry9 * 19;
    h9 -= carry9 * ((unsigned long long)1L << 25);

    carry0 = (h0 + (long long)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((unsigned long long)1L << 26);

    for(int I=0; I<10; ++I)
        h[I] = (int32_t) prod[I*3];  
}
