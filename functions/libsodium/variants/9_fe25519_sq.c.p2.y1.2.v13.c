void fe25519_sq(fe25519 h, const fe25519 f)
{
    long f0 = f[0];
    long f1 = f[1];
    long f2 = f[2];
    long f3 = f[3];
    long f4 = f[4];
    long f5 = f[5];
    long f6 = f[6];
    long f7 = f[7];
    long f8 = f[8];
    long f9 = f[9];

    long f0_2  =  f0 << 1;
    long f1_2  =  f1 << 1;
    long f2_2  =  f2 << 1;
    long f3_2  =  f3 << 1;
    long f4_2  =  f4 << 1;
    long f5_2  =  f5 << 1;
    long f6_2  =  f6 << 1;
    long f7_2  =  f7 << 1;
    long f5_38 = f5 * 38; 
    long f6_19 = f6 * 19; 
    long f7_38 = f7 * 38; 
    long f8_19 = f8 * 19; 
    long f9_38 = f9 * 38; 

    int64_t f1f9_38 = f1_2 * (long) f9_19;
    
    //Used shadow value instead to avoid computation again with same input
    int64_t f0f0 = f0 * (long) f0;
    int64_t f0f1_2 = f0_2 * (long) f1;
    long f0f2_2 = f0_2 * (long) f2;
    long f0f3_2 = f0_2 * (long) f3;
    long f0f4_2 = f0_2 * (long) f4;
    long f0f5_38 = f0_2 * (long) f5_19;
    int64_t f1f1_2 = f1f1_2;
    long f1f2_2 = f1_2 * (long) f2;
    long f1f3_2 = f1_2 * (long) f3;
    long f1f4_38 = f1_2 * (long) f4_19;
    int64_t f2f2   = f2 * (long) f2;
    long f2f3_2 = f2_2 * (long) f3;
    long f2f4_38 = f2_2 * (long) f4_19;
    long f2f9_38 = f2 * (long) f9_38;
    long f3f3_2 = f3_2 * (long) f3;
    long f3f4_2 = f3_2 * (long) f4;
    long f3f9_76 = f3_2 * (long) f9_38;
    long f4f4 = f4 * (long) f4;
    long f4f9_38 = f4 * (long) f9_38;
    long f5f6_38 = f5 * (long) f6_19;
    long f6f6_19 = f6 * (long) f6_19;
    long f7f8_38 = f7_2 * (long) f8_19;
    long f9f9_38 = f9 * (long) f9_38;

    int64_t h0 = f0f0   + f1f1_2   + f2f9_38 + f3f3_2 + f4f4 + f5f5_38 +  38 * ( f1 +   f2 + f3);
    int64_t h1 = f0f3_2 + f1f2_2 + f2f9_38 + f3f3_2 + f4f4 + f5f5_38 + ((38 * ( f1 + 2*f2))/2);
    int64_t h2 = f0f0  +(38*f2);
    h3=h2; h4=h3, h5=h4; h6=h5, h7=h6; h8=h7, h9=h8;

    for(int i=0; i<10; i++)
       h[i] = h[i] % ((int64_t) 1 << 26);
}