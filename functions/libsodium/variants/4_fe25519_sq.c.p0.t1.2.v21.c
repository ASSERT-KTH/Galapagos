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

    int32_t twice_f0  = f0 * 2;
    int32_t twice_f1  = f1 * 2;
    int32_t twice_f2  = f2 * 2;
    int32_t twice_f3  = f3 * 2;
    int32_t twice_f4  = f4 * 2;
    int32_t twice_f5  = f5 * 2;
    int32_t twice_f6  = f6 * 2;
    int32_t twice_f7  = f7 * 2;
    int32_t f5_times_38 = 38 * f5; /* 1.959375*2^30 */
    int32_t f6_times_19 = 19 * f6; /* 1.959375*2^30 */
    int32_t f7_times_38 = 38 * f7; /* 1.959375*2^30 */
    int32_t f8_times_19 = 19 * f8; /* 1.959375*2^30 */
    int32_t f9_times_38 = 38 * f9; /* 1.959375*2^30 */

    int64_t square0    = f0 * (int64_t) f0;
    int64_t posH1  = twice_f0 * (int64_t) f1;
    int64_t posH2  = twice_f0 * (int64_t) f2;
    int64_t posH3  = twice_f0 * (int64_t) f3;
    int64_t posH4  = twice_f0 * (int64_t) f4;
    int64_t posH5  = twice_f0 * (int64_t) f5;
    int64_t posH6  = twice_f0 * (int64_t) f6;
    int64_t posH7  = twice_f0 * (int64_t) f7;
    
    h[0] = (int32_t) square0;
    h[1] = (int32_t) posH1;
    h[2] = (int32_t) posH2;
    h[3] = (int32_t) posH3;
    h[4] = (int32_t) posH4;
    h[5] = (int32_t) posH5;
    h[6] = (int32_t) posH6;
    h[7] = (int32_t) posH7;

    int64_t f0_times_2_times_f8_short  = twice_f0 * (int64_t) f8;
    int64_t f0_times_2_times_f9_short  = twice_f0 * (int64_t) f9;
    int64_t f1_f1_short  = twice_f1 * (int64_t) f1;
    int64_t f1_times_2_times_f2_short  = twice_f1 * (int64_t) f2;
    int64_t f2_f2_short    = f2 * (int64_t) f2;

    h[8] = (int32_t) f0_times_2_times_f8_short;
    h[9] = (int32_t) f0_times_2_times_f9_short;
    h[2] += (int32_t) f1_f1_short;
    h[2] += (int32_t) f1_times_2_times_f2_short;
    h[2] += (int32_t) f2_f2_short;
}