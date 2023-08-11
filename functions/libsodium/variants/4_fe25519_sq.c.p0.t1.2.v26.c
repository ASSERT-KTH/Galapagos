fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f3 = f[3];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t f1_2  = f1 << 1;
    int32_t f0_2  = f0 << 1;
    int32_t f2_2  = f2 << 1;
    int32_t f3_2  = f3 << 1;
    int32_t f4_2  = f4 << 1;
    int32_t f5_2  = f5 << 1;
    int32_t f6_2  = f6 << 1;
    int32_t f7_2  = f7 << 1;
    int32_t f5_38 = f5 * 38;
    int32_t f6_19 = f6 * 19;
    int32_t f7_38 = f7 * 38;
    int32_t f8_19 = f8 * 19;
    int32_t f9_38 = f9 * 38;
...
}