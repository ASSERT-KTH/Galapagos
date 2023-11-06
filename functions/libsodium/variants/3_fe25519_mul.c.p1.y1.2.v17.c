Here is a variation of specific parts of the original function which will still maintain the same functionality:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    /* Different order */
    int32_t g0 = g[0];
    int32_t g1 = 19 * g[1];  
    int32_t g2 = 19 * g[2];  

    /* Combination */
    int32_t f5_2  = 2 * f[5];
    int32_t g5_19 = 19 * g[5];

    /* Combination */
    int64_t f0g0 = f[0] * (int64_t) g[0];
    int64_t f5g5_38  = f5_2 * (int64_t) g5_19;

    /* Expressions joined */
    int64_t h0 = f0g0 + f1g9_38 + f2g8_19 + f3g7_38 + f5g5_38 + f4g6_19 + f6g4_19 + f7g3_38 + f8g2_19 + f9g1_38;

    /*
     |h0| <= (1.65*1.65*2^52*(1+19+19+19+19)+1.65*1.65*2^50*(38+38+38+38+38))
     i.e. |h0| <= 1.4*2^60; narrower ranges for h4, h6, h8
     |h1| <= (1.65*1.65*2^51*(1+1+38+38))
     i.e. |h1| <= 1.7*2^57; narrower ranges for h5, h7, h9
     */

    carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);

    /*
     |h0| <= 2^25
     |h1| <= 1.7*2^57
     */

    carry1 = (h1 + (int64_t)(1L << 24)) >> 25;
    h2 += carry1;
    h1 -= carry1 * ((uint64_t) 1L << 25);

    /*
     |h1| <= 2^24;
     |h2| <= 1.41*2^60
     */

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    /* Some part of function removed */
}
