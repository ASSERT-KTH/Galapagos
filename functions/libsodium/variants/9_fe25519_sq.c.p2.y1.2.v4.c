void fe25519_sq(fe25519 h, const fe25519 f)
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

    int32_t f5_38 = 38 * f5;
    int32_t f6_19 = 19 * f6;
    int32_t f7_38 = 38 * f7;
    int32_t f8_19 = 19 * f8;
    int32_t f9_38 = 38 * f9;

    int64_t f0f5_38 = f0 * (int64_t) f5_38;
    int64_t f0f6_38 = f0 * (int64_t) f6_19 * 2;
    int64_t f0f7_38 = f0 * (int64_t) f7_38 * 2;
    int64_t f0f8_38 = f0 * (int64_t) f8_19 * 2;
    int64_t f0f9_38 = f0 * (int64_t) f9_38 * 2;
    int64_t f1f6_38 = f1 * (int64_t) f6_19 * 2;
    int64_t f1f7_38 = f1 * (int64_t) f7_38 * 2;
    int64_t f1f8_38 = f1 * (int64_t) f8_19 * 2;
    int64_t f1f9_76 = f1 * (int64_t) f9_38 * 2;
    int64_t f2f7_38 = f2 * (int64_t) f7_38 * 2;
    int64_t f2f8_38 = f2 * (int64_t) f8_19 * 2;
    int64_t f2f9_76 = f2 * (int64_t) f9_38 * 2;
    int64_t f3f8_38 = f3 * (int64_t) f8_19 * 2;
    int64_t f3f9_76 = f3 * (int64_t) f9_38 * 2;
    int64_t f4f9_76 = f4 * (int64_t) f9_38 * 2;

    int64_t h2 =     ((f4*f4) << 1)
               +   ((f3f6_38 + f2f7_38) << 1)
               +   ((f1f8_38 + f0f9_38) << 2)
               +   ((f0*f2) << 3)
               +   ((f1*f1) << 2);
    int64_t h8 =     ((f4*f9_38) << 1)
               +   ((f1*f7_38) << 1)
               +   (f3*f6_19)
               +   (f2*f5 * 10)
               +   (f0*f8 * 20)
               +   (f4 * f4)
               +   ((f0f6_38 + f3*f5_38 + f2+f7_38 + f1*f8_19) << 2);
    
    int64_t carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9;
    const int64_t carryMask = (1 << 30) - 1;

    carry0 = h8 >> 25;
    h9 = h9 + carry0;
    h8 = carryMask & h8;
    carry1 = h0 >> 26;
    h1 = h1 + carry1;
    h0 = carryMask & h0;
    carry2 = h1 >> 26;
    h2 = h2 + carry2; 
    h1 = carryMask & h1;
    carry3 = h2 >> 26;
    h3 = h3 + carry3;
    h2 = carryMask & h2;
    carry4 = h3 >> 26;
    h4 = h4 + carry4;
    h3 = carryMask & h3;

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