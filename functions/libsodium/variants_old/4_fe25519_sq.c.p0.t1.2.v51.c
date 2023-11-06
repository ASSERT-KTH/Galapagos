fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t elem0 = f[0];
    int32_t elem1 = f[1];
    int32_t elem2 = f[2];
    int32_t elem3 = f[3];
    int32_t elem4 = f[4];
    int32_t elem5 = f[5];
    int32_t elem6 = f[6];
    int32_t elem7 = f[7];
    int32_t elem8 = f[8];
    int32_t elem9 = f[9];

    int32_t elem0_2  = 2 * elem0;
    int32_t elem1_2  = 2 * elem1;
    int32_t elem2_2  = 2 * elem2;
    int32_t elem3_2  = 2 * elem3;
    int32_t elem4_2  = 2 * elem4;
    int32_t elem5_2  = 2 * elem5;
    int32_t elem6_2  = 2 * elem6;
    int32_t elem7_2  = 2 * elem7;
    int32_t elem5_38 = 38 * elem5; 
    int32_t elem6_19 = 19 * elem6; 
    int32_t elem7_38 = 38 * elem7; 
    int32_t elem8_19 = 19 * elem8;
    int32_t elem9_38 = 38 * elem9;

    int64_t elem0elem0    = elem0 * (int64_t) elem0;
    int64_t elem0elem1_2  = elem0_2 * (int64_t) elem1;
    int64_t elem0elem2_2  = elem0_2 * (int64_t) elem2;
    int64_t elem0elem3_2  = elem0_2 * (int64_t) elem3;
    int64_t elem0elem4_2  = elem0_2 * (int64_t) elem4;
    int64_t elem0elem5_2  = elem0_2 * (int64_t) elem5;
    int64_t elem0elem6_2  = elem0_2 * (int64_t) elem6;
    int64_t elem0elem7_2  = elem0_2 * (int64_t) elem7;
    int64_t elem0elem8_2  = elem0_2 * (int64_t) elem8;
    int64_t elem0elem9_2  = elem0_2 * (int64_t) elem9;
    int64_t elem1elem1_2  = elem1_2 * (int64_t) elem1;
    int64_t elem1elem2_2  = elem1_2 * (int64_t) elem2;
    int64_t elem1elem3_4  = elem1_2 * (int64_t) elem3_2;
    int64_t elem1elem4_2  = elem1_2 * (int64_t) elem4;
    int64_t elem1elem5_4  = elem1_2 * (int64_t) elem5_2;
    int64_t elem1elem6_2  = elem1_2 * (int64_t) elem6;
    int64_t elem1elem7_4  = elem1_2 * (int64_t) elem7_2;
    int64_t elem1elem8_2  = elem1_2 * (int64_t) elem8;
    int64_t elem1elem9_76 = elem1_2 * (int64_t) elem9_38;
    int64_t elem2elem2    = elem2 * (int64_t) elem2;
    int64_t elem2elem3_2  = elem2_2 * (int64_t) elem3;
    int64_t elem2elem4_2  = elem2_2 * (int64_t) elem4;
    int64_t elem2elem5_2  = elem2_2 * (int64_t) elem5;
    int64_t elem2elem6_2  = elem2_2 * (int64_t) elem6;
    int64_t elem2elem7_2  = elem2_2 * (int64_t) elem7;
    int64_t elem2elem8_38 = elem2_2 * (int64_t) elem8_19;
    int64_t elem2elem9_38 = elem2 * (int64_t) elem9_38;
    int64_t elem3elem3_2  = elem3_2 * (int64_t) elem3;
    int64_t elem3elem4_2  = elem3_2 * (int64_t) elem4;
    int64_t elem3elem5_4  = elem3_2 * (int64_t) elem5_2;
    int64_t elem3elem6_2  = elem3_2 * (int64_t) elem6;
    int64_t elem3elem7_76 = elem3_2 * (int64_t) elem7_38;
    int64_t elem3elem8_38 = elem3_2 * (int64_t) elem8_19;
    int64_t elem3elem9_76 = elem3_2 * (int64_t) elem9_38;
    int64_t elem4elem4    = elem4 * (int64_t) elem4;
    int64_t elem4elem5_2  = elem4_2 * (int64_t) elem5;
    int64_t elem4elem6_38 = elem4_2 * (int64_t) elem6_19;
    int64_t elem4elem7_38 = elem4 * (int64_t) elem7_38;
    int64_t elem4elem8_38 = elem4_2 * (int64_t) elem8_19;
    int64_t elem4elem9_38 = elem4 * (int64_t) elem9_38;
    int64_t elem5elem5_38 = elem5 * (int64_t) elem5_38;
    int64_t elem5elem6_38 = elem5_2 * (int64_t) elem6_19;
    int64_t elem5elem7_76 = elem5_2 * (int64_t) elem7_38;
    int64_t elem5elem8_38 = elem5_2 * (int64_t) elem8_19;
    int64_t elem5elem9_76 = elem5_2 * (int64_t) elem9_38;
    int64_t elem6elem6_19 = elem6 * (int64_t) elem6_19;
    int64_t elem6elem7_38 = elem6 * (int64_t) elem7_38;
    int64_t elem6elem8_38 = elem6_2 * (int64_t) elem8_19;
    int64_t elem6elem9_38 = elem6 * (int64_t) elem9_38;
    int64_t elem7elem7_38 = elem7 * (int64_t) elem7_38;
    int64_t elem7elem8_38 = elem7_2 * (int64_t) elem8_19;
    int64_t elem7elem9_76 = elem7_2 * (int64_t) elem9_38;
    int64_t elem8elem8_19 = elem8 * (int64_t) elem8_19;
    int64_t elem8elem9_38 = elem8 * (int64_t) elem9_38;
    int64_t elem9elem9_38 = elem9 * (int64_t) elem9_38;

    int64_t result0 = elem0elem0 + elem1elem9_76 + elem2elem8_38 + elem3elem7_76 + elem4elem6_38 + elem5elem5_38;
    int64_t result1 = elem0elem1_2 + elem2elem9_38 + elem3elem8_38 + elem4elem7_38 + elem5elem6_38;
    int64_t result2 = elem0elem2_2 + elem1elem1_2 + elem3elem9_76 + elem4elem8_38 + elem5elem7_76 + elem6elem6_19;
    int64_t result3 = elem0elem3_2 + elem1elem2_2 + elem4elem9_38 + elem5elem8_38 + elem6elem7_38;
    int64_t result4 = elem0elem4_2 + elem1elem3_4 + elem2elem2 + elem5elem9_76 + elem6elem8_38 + elem7elem7_38;
    int64_t result5 = elem0elem5_2 + elem1elem4_2 + elem2elem3_2 + elem6elem9_38 + elem7elem8_38;
    int64_t result6 = elem0elem6_2 + elem1elem5_4 + elem2elem4_2 + elem3elem3_2 + elem7elem9_76 + elem8elem8_19;
    int64_t result7 = elem0elem7_2 + elem1elem6_2 + elem2elem5_2 + elem3elem4_2 + elem8elem9_38;
    int64_t result8 = elem0elem8_2 + elem1elem7_4 + elem2elem6_2 + elem3elem5_4 + elem4elem4 + elem9elem9_38;
    int64_t result9 = elem0elem9_2 + elem1elem8_2 + elem2elem7_2 + elem3elem6_2 + elem4elem5_2;

    int64_t carry0;
    int64_t carry1;
    int64_t carry2;
    int64_t carry3;
    int64_t carry4;
    int64_t carry5;
    int64_t carry6;
    int64_t carry7;
    int64_t carry8;
    int64_t carry9;

    carry0 = (result0 + (int64_t)(1L << 25)) >> 26;
    result1 += carry0;
    result0 -= carry0 * ((uint64_t) 1L << 26);
    carry4 = (result4 + (int64_t)(1L << 25)) >> 26;
    result5 += carry4;
    result4 -= carry4 * ((uint64_t) 1L << 26);

    carry1 = (result1 + (int64_t)(1L << 24)) >> 25;
    result2 += carry1;
    result1 -= carry1 * ((uint64_t) 1L << 25);
    carry5 = (result5 + (int64_t)(1L << 24)) >> 25;
    result6 += carry5;
    result5 -= carry5 * ((uint64_t) 1L << 25);

    carry2 = (result2 + (int64_t)(1L << 25)) >> 26;
    result3 += carry2;
    result2 -= carry2 * ((uint64_t) 1L << 26);
    carry6 = (result6 + (int64_t)(1L << 25)) >> 26;
    result7 += carry6;
    result6 -= carry6 * ((uint64_t) 1L << 26);

    carry3 = (result3 + (int64_t)(1L << 24)) >> 25;
    result4 += carry3;
    result3 -= carry3 * ((uint64_t) 1L << 25);
    carry7 = (result7 + (int64_t)(1L << 24)) >> 25;
    result8 += carry7;
    result7 -= carry7 * ((uint64_t) 1L << 25);

    carry4 = (result4 + (int64_t)(1L << 25)) >> 26;
    result5 += carry4;
    result4 -= carry4 * ((uint64_t) 1L << 26);
    carry8 = (result8 + (int64_t)(1L << 25)) >> 26;
    result9 += carry8;
    result8 -= carry8 * ((uint64_t) 1L << 26);

    carry9 = (result9 + (int64_t)(1L << 24)) >> 25;
    result0 += carry9 * 19;
    result9 -= carry9 * ((uint64_t) 1L << 25);

    carry0 = (result0 + (int64_t)(1L << 25)) >> 26;
    result1 += carry0;
    result0 -= carry0 * ((uint64_t) 1L << 26);

    h[0] = (int32_t) result0;
    h[1] = (int32_t) result1;
    h[2] = (int32_t) result2;
    h[3] = (int32_t) result3;
    h[4] = (int32_t) result4;
    h[5] = (int32_t) result5;
    h[6] = (int32_t) result6;
    h[7] = (int32_t) result7;
    h[8] = (int32_t) result8;
    h[9] = (int32_t) result9;
}