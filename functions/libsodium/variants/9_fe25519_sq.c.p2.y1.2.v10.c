fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f0 = f[0];
    int64_t f1 = f[1];
    int64_t f2 = f[2];
    int64_t f3 = f[3];
    int64_t f4 = f[4];
    int64_t f5 = f[5];
    int64_t f6 = f[6];
    int64_t f7 = f[7];
    int64_t f8 = f[8];
    int64_t f9 = f[9];

    f0 <<= 1;
    f1 <<= 1;
    f2 <<= 1;
    f3 <<= 1;
    f4 <<= 1;
    f5 = (f5 << 1) * 19;
    f6 = (f6 << 1) * 19;
    f7 = (f7 << 1) * 19;
    f8 = (f8 << 1) * 19;
    f9 = (f9 << 1) * 19;

    int64_t tmp0 = f0*f0 + f1*f9 + f2*f8 + f3*f7 + f4*f6;
    int64_t tmp1 = f0*f1 + f2*f9 + f3*f8 + f4*f7;
    int64_t tmp2 = f0*f2 + f1*f1 + f3*f9 + f4*f8 + f6*f6;
    int64_t tmp3 = f0*f3 + f1*f2 + f4*f9 + f6*f7;
    int64_t tmp4 = f0*f4 + f1*f3 + f2*f2 + f5*f9 + f6*f8 + f7*f7;
    int64_t tmp5 = f0*f5 + f1*f4 + f2*f3 + f4*f9 + f6*f7;
    int64_t tmp6 = f0*f6 + f1*f5 + f2*f4 + f3*f3 + f6*f9 + f7*f8;
    int64_t tmp7 = f0*f7 + f1*f6 + f2*f5 + f3*f4 + f8*f8;
    int64_t tmp8 = f0*f8 + f1*f7 + f2*f6 + f3*f5 + f4*f4 + f9*f9;
    int64_t tmp9 = f0*f9 + f1*f8 + f2*f7 + f3*f6 + f4*f5;

    h[0] = (tmp0 + 0x2000000) >> 26; tmp1 += (h[0] - (tmp0 >> 26)); tmp0 &= 0x3ffffff;
    h[1] = (tmp1 + 0x1000000) >> 25; tmp2 += (h[1] - (tmp1 >> 25)); tmp1 &= 0x1ffffff;
    h[2] = (tmp2 + 0x2000000) >> 26; tmp3 += (h[2] - (tmp2 >> 26)); tmp2 &= 0x3ffffff;
    h[3] = (tmp3 + 0x1000000) >> 25; tmp4 += (h[3] - (tmp3 >> 25)); tmp3 &= 0x1ffffff;
    h[4] = (tmp4 + 0x2000000) >> 26; tmp5 += (h[4] - (tmp4 >> 26)); tmp4 &= 0x3ffffff;
    h[5] = (tmp5 + 0x1000000) >> 25; tmp6 += (h[5] - (tmp5 >> 25)); tmp5 &= 0x1ffffff;
    h[6] = (tmp6 + 0x2000000) >> 26; tmp7 += (h[6] - (tmp6 >> 26)); tmp6 &= 0x3ffffff;
    h[7] = (tmp7 + 0x1000000) >> 25; tmp8 += (h[7] - (tmp7 >> 25)); tmp7 &= 0x1ffffff;
    h[8] = (tmp8 + 0x2000000) >> 26; tmp9 += (h[8] - (tmp8 >> 26)); tmp8 &= 0x3ffffff;
    h[9] = (tmp9 + 0x1000000) >> 25; tmp0 = ((tmp0 + (h[9] - (temp9 >> 25)) * 19) & 0x3ffffff)
             + ((tmp1 * 0x4000000) | (tmp0 >> 26));
    h[0] = tmp0;
    h[1] = tmp1 & 0x1ffffff;
    h[2] = tmp2;
    h[3] = tmp3;
    h[4] = tmp4;
    h[5] = tmp5;
    h[6] = tmp6;
    h[7] = tmp7;
    h[8] = tmp8;
    h[9] = tmp9;
}