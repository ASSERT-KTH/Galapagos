fe25519_sq(fe25519 g, const fe25519 f)
{
    int32_t _f0 = f[0];
    int32_t _f1 = f[1];
    int32_t _f2 = f[2];
    int32_t _f3 = f[3];
    int32_t _f4 = f[4];
    int32_t _f5 = f[5];
    int32_t _f6 = f[6];
    int32_t _f7 = f[7];
    int32_t _f8 = f[8];
    int32_t _f9 = f[9];

    int32_t f0_2  = _f0 * 2;
    int32_t f1_2  = _f1 * 2;
    int32_t f2_2  = _f2 * 2;
    int32_t f3_2  = _f3 * 2;
    int32_t f4_2  = _f4 * 2;
    int32_t f5_2  = _f5 * 2;
    int32_t f6_2  = _f6 * 2;
    int32_t f7_2  = _f7 * 2;
    int32_t f5_38 = 38 * _f5;
    int32_t f6_19 = 19 * _f6;
    int32_t f7_38 = 38 * _f7;
    int32_t f8_19 = 19 * _f8;
    int32_t f9_38 = 38 * _f9;

    int64_t f0f0    = _f0 * (int64_t) _f0;
    int64_t f0f1_2  = f0_2 * (int64_t) _f1;
    int64_t f0f2_2  = f0_2 * (int64_t) _f2;
    int64_t f0f3_2  = f0_2 * (int64_t) _f3;
    int64_t f0f4_2  = f0_2 * (int64_t) _f4;
    int64_t f0f5_2  = f0_2 * (int64_t) _f5;
    int64_t f0f6_2  = f0_2 * (int64_t) _f6;
    int64_t f0f7_2  = f0_2 * (int64_t) _f7;
    int64_t f0f8_2  = f0_2 * (int64_t) _f8;
    int64_t f0f9_2  = f0_2 * (int64_t) _f9;
    int64_t f1f1_2  = f1_2 * (int64_t) _f1;
    int64_t f1f2_2  = f1_2 * (int64_t) _f2;
    int64_t f1f3_4  = f1_2 * (int64_t) f3_2;
    int64_t f1f4_2  = f1_2 * (int64_t) _f4;  
    ...

    int64_t carry0;
    int64_t carry1;
    int64_t carry2;
    ...
    
    carry0 = (l0 + (int64_t)(1L << 25)) >> 26;
    l1 += carry0;
    l0 -= carry0 * ((uint64_t) 1L << 26);
    carry4 = (l4 + (int64_t)(1L << 25)) >> 26;
    l5 += carry4;
    l4 -= carry4 * ((uint64_t) 1L << 26);

    ...

    g[0] = (int32_t) l0;
    g[1] = (int32_t) l1;
    g[2] = (int32_t) l2;
    g[3] = (int32_t) l3;
    ...
}