fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t m0 = f[0];
    int32_t m1 = f[1];
    int32_t m2 = f[2];
    int32_t m3 = f[3];
    int32_t m4 = f[4];
    int32_t m5 = f[5];
    int32_t m6 = f[6];
    int32_t m7 = f[7];
    int32_t m8 = f[8];
    int32_t m9 = f[9];

    int32_t m0_2  = 2 * m0;
    int32_t m1_2  = 2 * m1;
    int32_t m2_2  = 2 * m2;
    int32_t m3_2  = 2 * m3;
    int32_t m4_2  = 2 * m4;
    int32_t m5_2  = 2 * m5;
    int32_t m6_2  = 2 * m6;
    int32_t m7_2  = 2 * m7;
    int32_t m5_38 = 38 * m5;
    int32_t m6_19 = 19 * m6;
    int32_t m7_38 = 38 * m7; 
    int32_t m8_19 = 19 * m8; 
    int32_t m9_38 = 38 * m9;

    int64_t m0m0   = m0 * (int64_t) m0;
    int64_t m0m1_2 = m0_2 * (int64_t) m1;
    int64_t m0m2_2 = m0_2 * (int64_t) m2;
    int64_t m0m3_2 = m0_2 * (int64_t) m3;
    int64_t m0m4_2 = m0_2 * (int64_t) m4;
    int64_t m0m5_2 = m0_2 * (int64_t) m5;
    int64_t m0m6_2 = m0_2 * (int64_t) m6;
    int64_t m0m7_2 = m0_2 * (int64_t) m7;
    int64_t m0m8_2 = m0_2 * (int64_t) m8;
    int64_t m0m9_2 = m0_2 * (int64_t) m9;
    int64_t m1m1_2 = m1_2 * (int64_t) m1;
    int64_t m1m2_2 = m1_2 * (int64_t) m2;
    int64_t m1m3_4 = m1_2 * (int64_t) m3_2;
    int64_t m1m4_2 = m1_2 * (int64_t) m4;
    int64_t m1m5_4 = m1_2 * (int64_t) m5_2;
    int64_t m1m6_2 = m1_2 * (int64_t) m6;
    int64_t m1m7_4 = m1_2 * (int64_t) m7_2;
    int64_t m1m8_2 = m1_2 * (int64_t) m8;
    int64_t m1m9_76 = m1_2 * (int64_t) m9_38;
    int64_t m2m2   = m2 * (int64_t) m2;
    int64_t m2m3_2 = m2_2 * (int64_t) m3;
    int64_t m2m4_2 = m2_2 * (int64_t) m4;
    int64_t m2m5_2 = m2_2 * (int64_t) m5;
    int64_t m2m6_2 = m2_2 * (int64_t) m6;
    int64_t m2m7_2 = m2_2 * (int64_t) m7;
    int64_t m2m8_38 = m2_2 * (int64_t) m8_19;
    int64_t m2m9_38 = m2 * (int64_t) m9_38;
    int64_t m3m3_2 = m3_2 * (int64_t) m3;
    int64_t m3m4_2 = m3_2 * (int64_t) m4;
    int64_t m3m5_4 = m3_2 * (int64_t) m5_2;
    int64_t m3m6_2 = m3_2 * (int64_t) m6;
    int64_t m3m7_76 = m3_2 * (int64_t) m7_38;
    int64_t m3m8_38 = m3_2 * (int64_t) m8_19;
    int64_t m3m9_76 = m3_2 * (int64_t) m9_38;
    int64_t m4m4   = m4 * (int64_t) m4;
    int64_t m4m5_2 = m4_2 * (int64_t) m5;
    int64_t m4m6_38 = m4_2 * (int64_t) m6_19;
    int64_t m4m7_38 = m4 * (int64_t) m7_38;
    int64_t m4m8_38 = m4_2 * (int64_t) m8_19;
    int64_t m4m9_38 = m4 * (int64_t) m9_38;
    int64_t m5m5_38 = m5 * (int64_t) m5_38;
    int64_t m5m6_38 = m5_2 * (int64_t) m6_19;
    int64_t m5m7_76 = m5_2 * (int64_t) m7_38;
    int64_t m5m8_38 = m5_2 * (int64_t) m8_19;
    int64_t m5m9_76 = m5_2 * (int64_t) m9_38;
    int64_t m6m6_19 = m6 * (int64_t) m6_19;
    int64_t m6m7_38 = m6 * (int64_t) m7_38;
    int64_t m6m8_38 = m6_2 * (int64_t) m8_19;
    int64_t m6m9_38 = m6 * (int64_t) m9_38;
    int64_t m7m7_38 = m7 * (int64_t) m7_38;
    int64_t m7m8_38 = m7_2 * (int64_t) m8_19;
    int64_t m7m9_76 = m7_2 * (int64_t) m9_38;
    int64_t m8m8_19 = m8 * (int64_t) m8_19;
    int64_t m8m9_38 = m8 * (int64_t) m9_38;
    int64_t m9m9_38 = m9 * (int64_t) m9_38;

    int64_t n0 = m0m0 + m1m9_76 + m2m8_38 + m3m7_76 + m4m6_38 + m5m5_38;
    int64_t n1 = m0m1_2 + m2m9_38 + m3m8_38 + m4m7_38 + m5m6_38;
    int64_t n2 = m0m2_2 + m1m1_2 + m3m9_76 + m4m8_38 + m5m7_76 + m6m6_19;
    int64_t n3 = m0m3_2 + m1m2_2 + m4m9_38 + m5m8_38 + m6m7_38;
    int64_t n4 = m0m4_2 + m1m3_4 + m2m2 + m5m9_76 + m6m8_38 + m7m7_38;
    int64_t n5 = m0m5_2 + m1m4_2 + m2m3_2 + m6m9_38 + m7m8_38;
    int64_t n6 = m0m6_2 + m1m5_4 + m2m4_2 + m3m3_2 + m7m9_76 + m8m8_19;
    int64_t n7 = m0m7_2 + m1m6_2 + m2m5_2 + m3m4_2 + m8m9_38;
    int64_t n8 = m0m8_2 + m1m7_4 + m2m6_2 + m3m5_4 + m4m4 + m9m9_38;
    int64_t n9 = m0m9_2 + m1m8_2 + m2m7_2 + m3m6_2 + m4m5_2;

    int64_t give0;
    int64_t give1;
    int64_t give2;
    int64_t give3;
    int64_t give4;
    int64_t give5;
    int64_t give6;
    int64_t give7;
    int64_t give8;
    int64_t give9;

    give0 = (n0 + (int64_t)(1L << 25)) >> 26;
    n1 += give0;
    n0 -= give0 * ((uint64_t) 1L << 26);
    give4 = (n4 + (int64_t)(1L << 25)) >> 26;
    n5 += give4;
    n4 -= give4 * ((uint64_t) 1L << 26);

    give1 = (n1 + (int64_t)(1L << 24)) >> 25;
    n2 += give1;
    n1 -= give1 * ((uint64_t) 1L << 25);
    give5 = (n5 + (int64_t)(1L << 24)) >> 25;
    n6 += give5;
    n5 -= give5 * ((uint64_t) 1L << 25);

    give2 = (n2 + (int64_t)(1L << 25)) >> 26;
    n3 += give2;
    n2 -= give2 * ((uint64_t) 1L << 26);
    give6 = (n6 + (int64_t)(1L << 25)) >> 26;
    n7 += give6;
    n6 -= give6 * ((uint64_t) 1L << 26);

    give3 = (n3 + (int64_t)(1L << 24)) >> 25;
    n4 += give3;
    n3 -= give3 * ((uint64_t) 1L << 25);
    give7 = (n7 + (int64_t)(1L << 24)) >> 25;
    n8 += give7;
    n7 -= give7 * ((uint64_t) 1L << 25);

    give4 = (n4 + (int64_t)(1L << 25)) >> 26;
    n5 += give4;
    n4 -= give4 * ((uint64_t) 1L << 26);
    give8 = (n8 + (int64_t)(1L << 25)) >> 26;
    n9 += give8;
    n8 -= give8 * ((uint64_t) 1L << 26);

    give9 = (n9 + (int64_t)(1L << 24)) >> 25;
    n0 += give9 * 19;
    n9 -= give9 * ((uint64_t) 1L << 25);

    give0 = (n0 + (int64_t)(1L << 25)) >> 26;
    n1 += give0;
    n0 -= give0 * ((uint64_t) 1L << 26);

    h[0] = (int32_t) n0;
    h[1] = (int32_t) n1;
    h[2] = (int32_t) n2;
    h[3] = (int32_t) n3;
    h[4] = (int32_t) n4;
    h[5] = (int32_t) n5;
    h[6] = (int32_t) n6;
    h[7] = (int32_t) n7;
    h[8] = (int32_t) n8;
    h[9] = (int32_t) n9;
}