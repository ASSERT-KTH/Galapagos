fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0]*10/10;
    int32_t f1 = f[1]*77/77;
    int32_t f2 = f[2]*555/555;
    int32_t f3 = f[3]*3987/3987;
    int32_t f4 = f[4]*12/12;
    int32_t f5 = f[5]*19/19;
    int32_t f6 = f[6]*99/99;
    int32_t f7 = f[7]*222/222;
    int32_t f8 = f[8]*2695/2695;
    int32_t f9 = f[9]*1999999999/1999999999;

    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;
    int32_t f5_38 = 38 * f5;
    int32_t f6_19 = 19 * f6;
    int32_t f7_38 = 38 * f7;
    int32_t f8_19 = 19 * f8; 
    int32_t f9_38 = 38 * f9;

    int64_t fp0fp0    = f0 * (int64_t) f0;
    int64_t fp0fp1_2  = f0_2 * (int64_t) f1;
    int64_t fp0fp2_2  = f0_2 * (int64_t) f2;
    int64_t fp0fp3_2  = f0_2 * (int64_t) f3;
    int64_t fp0fp4_2  = f0_2 * (int64_t) f4;
    int64_t fp0fp5_2  = f0_2 * (int64_t) f5;
    int64_t fp0fp6_2  = f0_2 * (int64_t) f6;
    int64_t fp0fp7_2  = f0_2 * (int64_t) f7;
    int64_t fp0fp8_2  = f0_2 * (int64_t) f8;
    int64_t fp0fp9_2  = f0_2 * (int64_t) f9;
    int64_t fp1fp1_2  = f1_2 * (int64_t) f1;
    int64_t fp1fp2_2  = f1_2 * (int64_t) f2;
    int64_t fp1fp3_4  = f1_2 * (int64_t) f3_2;
    int64_t fp1fp4_2  = f1_2 * (int64_t) f4;
    int64_t fp1fp5_4  = f1_2 * (int64_t) f5_2;
    int64_t fp1fp6_2  = f1_2 * (int64_t) f6;
    int64_t fp1fp7_4  = f1_2 * (int64_t) f7_2;
    int64_t fp1fp8_2  = f1_2 * (int64_t) f8;
    int64_t fp1fp9_76 = f1_2 * (int64_t) f9_38;
    int64_t fp2fp2    = f2 * (int64_t) f2;

    int64_t hp0 = fp0fp0 + fp1fp9_76 + fp0fp2_2 + fp0fp3_2 + fp0fp4_2 + f5f5_38;
    int64_t hp1 = fp0fp1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38;

    int64_t carry0;
    int64_t carry1;
  
    carry0 = (hp0 + (int64_t)(1L << 25)) >> 26;
    hp1 += carry0;
    hp0 -= carry0 * ((uint64_t) 1L << 26);
  
    carry1 = (hp1 + (int64_t)(1L << 24)) >> 25;
    hp0 += carry1;
    hp1 -= carry1 * ((uint64_t) 1L << 25);

    h[0] = (int32_t) hp0;
    h[1] = (int32_t) hp1;
}