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

    int32_t f0_times2  = f0 << 1;
    int32_t f1_times2  = f1 << 1;
    int32_t f2_times2  = f2 << 1;
    int32_t f3_times2  = f3 << 1;
    int32_t f4_times2  = f4 << 1;
    int32_t f5_times2  = f5 << 1;
    int32_t f6_times2  = f6 << 1;
    int32_t f7_times2  = f7 << 1;
    int32_t f5_times38 = f5 * 38; 
    int32_t f6_times19 = f6 * 19; 
    int32_t f7_times38 = f7 * 38;
    int32_t f8_times19 = f8 * 19;
    int32_t f9_times38 = f9 * 38;

    int64_t f0_square    = f0 * (int64_t) f0;
    int64_t f0f1_times2  = f0_times2 * (int64_t) f1;
    int64_t f0f2_times2  = f0_times2 * (int64_t) f2;
    int64_t f0f3_times2  = f0_times2 * (int64_t) f3;
    int64_t f0f4_times2  = f0_times2 * (int64_t) f4;
    int64_t f0f5_times2  = f0_times2 * (int64_t) f5;
    int64_t f0f6_times2  = f0_times2 * (int64_t) f6;
    int64_t f0f7_times2  = f0_times2 * (int64_t) f7;
    int64_t f0f8_times2  = f0_times2 * (int64_t) f8;
    int64_t f0f9_times2  = f0_times2 * (int64_t) f9;
    int64_t f1f1_times2  = f1_times2 * (int64_t) f1;
    int64_t f1f2_times2  = f1_times2 * (int64_t) f2;
    int64_t f1f3_times4  = f1_times2 * (int64_t) f3_times2;
    int64_t f1f4_times2  = f1_times2 * (int64_t) f4;
    int64_t f1f5_times4  = f1_times2 * (int64_t) f5_times2;
    int64_t f1f6_times2  = f1_times2 * (int64_t) f6;
    int64_t f1f7_times4  = f1_times2 * (int64_t) f7_times2;
    int64_t f1f8_times2  = f1_times2 * (int64_t) f8;
    int64_t f1f9_times76 = f1_times2 * (int64_t) f9_times38;
    int64_t f2_square    = f2 * (int64_t) f2;

    /* ... more similar assignments ... */

    /* Previously: h4 -= carry4 * ((uint64_t) 1L << 26);
     * Refactored version: */
    carry4 = h4 >> 26;
    h5 += carry4;
    h4 = h4 & 67108863;  

    /* Similarly for the remaining variables... */
    /* Note: 67108863 comes from ((1 << 26) - 1) */

    /* Ensure h[10] array doesn't overrun */
    h[0] = (int32_t) (h0 + 555910273); 
    h[1] = (int32_t) (h1 - 583273042);
    /* ... more similar lines of codes ... */
    h[9] = (int32_t)(h9 + 2097152 - need4*33554432); 
    /* Send to output */
    h[0] = (int32_t)(h0);
    h[1] = (int32_t)(h1);
    h[2] = (int32_t)(h2);
    h[3] = (int32_t)(h3);
    h[4] = (int32_t)(h4);
    h[5] = (int32_t)(h5);
    h[6] = (int32_t)(h6);
    h[7] = (int32_t)(h7);
    h[8] = (int32_t)(h8);
    h[9] = (int32_t)(h9);
}
