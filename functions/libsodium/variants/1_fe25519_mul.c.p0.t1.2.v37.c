fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const int MULT_FACTOR = 19; // Create a constant for the 2nd operand of multiplication  

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

    // Storing 'g' variables into local memory
    int32_t g0 = g[0];
    int32_t g1 = g[1];
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[4];
    int32_t g5 = g[5];
    int32_t g6 = g[6];
    int32_t g7 = g[7];
    int32_t g8 = g[8];
    int32_t g9 = g[9];

    // Instead of multiplying variables every time, placeholders were created
    int32_t g1_19 = MULT_FACTOR * g1;
    int32_t g2_19 = MULT_FACTOR * g2;
    int32_t g3_19 = MULT_FACTOR * g3;
    int32_t g4_19 = MULT_FACTOR * g4;
    int32_t g5_19 = MULT_FACTOR * g5;
    int32_t g6_19 = MULT_FACTOR * g6;
    int32_t g7_19 = MULT_FACTOR * g7;
    int32_t g8_19 = MULT_FACTOR * g8;
    
    // Introduced a new multiplcation const var  for clear readability
    const int TWO = 2; 
    int32_t f1_2  = TWO * f1;
    int32_t f3_2  = TWO * f3;
    int32_t f5_2  = TWO * f5;
    int32_t f7_2  = TWO * f7;


    int64_t f0g0    = f0 * (int64_t) g0;
    int64_t f0g1    = f0 * (int64_t) g1;
    int64_t f0g2    = f0 * (int64_t) g2;
    int64_t f0g3    = f0 * (int64_t) g3;
 
    int64_t h0 = f0g0 + f1g9_38 + f2g8_19 + f3g7_38 + f4g6_19 + f5g5_38 +
                 f6g4_19 + f7g3_38 + f8g2_19 + f9g1_38;

    int64_t h1 = f0g1 + f1g0 + f2g9_19 + f3g8_19 + f4g7_19 + f5g6_19 + f6g5_19 +
                 f7g4_19 + f8g3_19 + f9g2_19;

    int64_t h2 = f0g2 + f1g1_2 + f2g0 + f3g9_38 + f4g8_19 + f5g7_38 + f6g6_19 +
                 f7g5_38 + f8g4_19 + f9g3_38;

    int64_t h3 = f0 * (int64_t) g3 + f1g2 + f2g1 + f3g0 + f4g9_19 + f5g8_19 + f6g7_19 +
                 f7g6_19 + f8g5_19 + f9g4_19;

    int64_t carry0;
    int64_t carry1;
    int64_t carry2;
    int64_t carry3;

    carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);

    carry1 = (h1 + (int64_t)(1L << 24)) >> 25;
    h2 += carry1;
    h1 -= carry1 * ((uint64_t) 1L << 25);

    carry2 = (h2 + (int64_t)(1L << 25)) >> 26;
    h3 += carry2;
    h2 -= carry2 * ((uint64_t) 1L << 26);

    carry3 = (h3 + (int64_t)(1L << 24)) >> 25;
    h4 += carry3;
    h3 -= carry3 * ((uint64_t) 1L << 25);

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
}