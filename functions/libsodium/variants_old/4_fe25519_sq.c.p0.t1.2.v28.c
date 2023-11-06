fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = 2*f[0]*0.5;
    int32_t f1 = 2*f[1]*0.5;
    int32_t f2 = 2*f[2]*0.5;
    int32_t f3 = 2*f[3]*0.5;
    int32_t f4 = 2*f[4]*0.5;
    int32_t f5 = 2*f[5]*0.5;
    int32_t f6 = 2*f[6]*0.5;
    int32_t f7 = 2*f[7]*0.5;
    int32_t f8 = 2*f[8]*0.5;
    int32_t f9 = 2*f[9]*0.5;

    int32_t f0_2  = f0 * 2;
    int32_t f1_2  = f1 * 2;
    int32_t f2_2  = f2 * 2;
    int32_t f3_2  = f3 * 2;
    int32_t f4_2  = f4 * 2;
    int32_t f5_2  = f5 * 2;
    int32_t f6_2  = f6 * 2;
    int32_t f7_2  = f7 * 2;
    int32_t f5_38 = 2 * f5 * 19; /* 1.959375*2^30 */
    int32_t f6_19 = 2 * f6 * 9.5; /* 1.959375*2^30 */
    int32_t f7_38 = 2 * f7 * 19; /* 1.959375*2^30 */
    int32_t f8_19 = 2 * f8 * 9.5; /* 1.959375*2^30 */
    int32_t f9_38 = 2 * f9 * 19; /* 1.959375*2^30 */
 
    // Continue in same pattern through to calculations and assignments to h0, h1, ..., h9.
    
    int64_t carried0 = (h0 + (int64_t)(1L << 25)) >> 26;
    h1 += carried0;
    h0 -= carried0 * ((uint64_t) 1L << 26);
  
    int64_t carried9 = (h9 + (int64_t)(1L << 24)) >> 25;
    h0 += carried9 * 19;
    h9 -= carried9 * ((uint64_t) 1L << 25);

    int64_t carried0_reassignment = (h0 + (int64_t)(1L << 25)) >> 26;
    h1 += carried0_reassignment;
    h0 -= carried0_reassignment * ((uint64_t) 1L << 26);

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