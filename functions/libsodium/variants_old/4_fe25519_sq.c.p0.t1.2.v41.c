fe25519_sq(fe25519 h, const fe25519 f)
{
    // Instead of assigning all f values to individual variables we will access them directly from the array 
    // Rename f0_2 to f0Double for increased clarity
    int32_t f0Double  = 2 * f[0];
    int32_t f1Double  = 2 * f[1];
    int32_t f2Double  = 2 * f[2];
    int32_t f3Double  = 2 * f[3];
    int32_t f4Double  = 2 * f[4];
    int32_t f5Double  = 2 * f[5];
    int32_t f6Double  = 2 * f[6];
    int32_t f7Double  = 2 * f[7];
    int32_t f5_38 = 38 * f[5]; /* 1.959375*2^30 */
    int32_t f6_19 = 19 * f[6]; /* 1.959375*2^30 */
    int32_t f7_38 = 38 * f[7]; /* 1.959375*2^30 */
    
    //  Due to limited intelise waiting code was split into several parts when it did not have to.
    // We Will combine as necessary

    int64_t f0f2_2  = f0Double * (int64_t) f[2];
    int64_t f0f9_2  = f0Double * (int64_t) f[9];;
    int64_t f1f1_2  = f1Double * (int64_t) f[1];
    int64_t f2f3_2  = f2Double * (int64_t) f[3];
    int64_t f1f3_4  = f1Double * (int64_t) f3Double;
    int64_t f3f5_4  = f3Double * (int64_t) f5Double;
    int64_t f4f5_2  = f4Double * (int64_t) f[5];
    
    // Very short equations will be combined in the final results h
    
    int64_t carry0,carry1,carry2,carry3,carry4,carry5,carry6,carry7,carry8,carry9;
    int64_t h[10];

    h[0] = f[0] * (int64_t) f[0] + f1Double * (int64_t) 38 * f[9]+ // f1f9_38
            f2Double * (int64_t) 19 * f[8]+ //f2f8-38
            f3Double * (int64_t) f7_38+
            f4Double * (int64_t) f6_19 +
            f[5]*(int64_t)f5_38;
    h[2] = f1f1_2+ f0f2_2+ f0f2_2 + f3Double * (int64_t) f9_38 +
            f4Double * (int64_t) f8_19 +
            f5Double* (int64_t) f7_38+
            f[6]* (int64_t) f6_19;


    carry0 = (h[0] + (int64_t)(1L << 25)) >> 26;
    h[1] += carry0;
    h[0]-= carry0 * ((uint64_t) 1L << 26);

    carry2 = (h[2] + (int64_t)(1L << 25)) >> 26;
    h[3] += carry2;
    h[2] -= carry2 * ((uint64_t) 1L << 26);

    carry0 = (h[0] + (int64_t)(1L << 25)) >> 26;
    h[1] += carry0;
    h[0] -= carry0 * ((uint64_t) 1L << 26);

    //No Changes to output
    h[0] = (int32_t) h[0];
    h[1] = (int32_t) h[1];
    h[2] = (int32_t) h[2];
    h[3] = (int32_t) h[3];
    h[4] = (int32_t) h[4];
    h[5] = (int32_t) h[5];
    h[6] = (int32_t) h[6];
    h[7] = (int32_t) h[7];
    h[8] = (int32_t) h[8];
    h[9] = (int32_t) h[9];
}