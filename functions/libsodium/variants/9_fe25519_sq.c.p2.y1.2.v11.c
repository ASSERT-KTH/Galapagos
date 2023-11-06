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

    int64_t h0 = f0 * (int64_t) f0;
    h0 += ( (2 * f0) * (int64_t) f1 ) + ( (2 * f0) * (int64_t) f2) + ( (2 * f0) * (int64_t) f3);
    h0 += ( (2 * f0) * (int64_t) f4) + ( (2 * f0) * (int64_t) f5) + ( (38 * f1) * (int64_t) f9);
    h0 += ( (19 * f2) * (int64_t) f8) + ( (38 * f3) * (int64_t) f7) + ( (19 * f4) * (int64_t) f6);

    int64_t h1 = (2 * f0) * (int64_t) f1 + (2 * f1) * (int64_t) f1 + f2 * (int64_t) f2 +
                ( (19 * f2) * (int64_t) f9) + ( (19 * f3) * (int64_t) f8) +
                ( (38 * f4) * (int64_t) f7) + ( (19 * f5) * (int64_t) f6);

    int64_t carry0 = (h0 >> 26);
    h0 -= carry0 << 26;
    h1 += carry0;

    int64_t h2 = (2 * f0) * (int64_t) f2 + 2 * (f2 * (int64_t) f1) +
                f3 * (int64_t) f3 + 2 * (f3 * (int64_t) f7_38) +
                f4 * (int64_t) f4 + (38 * f1) * (int64_t) f9 +
                (38 * f5) * (int64_t) f5_38 + f6_19 * (int64_t) f6_19;

    int64_t h3 = (2 * f0) * (int64_t) f3 + (2 * f1) * (int64_t) f2 +
                (2 * f8_19) * (int64_t) f8_19 +
                f5 * (int64_t) f4 + (38 * f6) * (int64_t) f6 +
                (38 * f7) * (int64_t) f5 + (38 * f2) * (int64_t) f7_38;

    h3 += (f3 * (int64_t) f5_2);

    int64_t carry1 = (h1 >> 25);
    h1 -= carry1 << 25;
    h2 += carry1;

    int64_t h4 = (2 * f0) * (int64_t) f4 + (2 * f1_2) * (int64_t) f3 +
                (2 * f2) * (int64_t) f2 + f4 * (int64_t) f4 +
                f5 * (int64_t) f5_38 + f6_f6_19 +
                (19 * f7_38 * f7_38) + f8_f8_38 +
                (38 * F9_38 * F9_38);

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
}
The computation now indexes into f and computes the floating point star expressions simultaneously. Rotation is expressed as right shift by n. Some operations reuse computations from within the same 'round' of h index computation, so no exactly identical computation is performed twice. The output assignments remain largely the same.