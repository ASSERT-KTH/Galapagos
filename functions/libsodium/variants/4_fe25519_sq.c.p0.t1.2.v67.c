fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];

    int32_t f0_2  = f0 << 1;
    int32_t f1_2  = f1 << 1;
    int32_t f2_2  = f2 << 1;
    int32_t f3_2  = f3 << 1;
    int32_t f4_2  = f4 << 1;
    int32_t f5_2  = f5 << 1;
    int32_t f6_2  = f6 << 1;
    int32_t f7_2  = f7 << 1;
    int32_t f5_38 = 38 * f5;
    int32_t f6_19 = 19 * f6;
    int32_t f7_38 = 38 * f7;
    int32_t f8_19 = 19 * f8;
    int32_t f9_38 = 38 * f9;

    int64_t f0f0    = f0 * (int64_t) f0;
    int64_t f0f1_2  = f0_2 * (int64_t) f1;
   //.......other codes remaining the same........//

   int64_t carry0 = (h0 + (int64_t)(1L << 25)) >> 26; h1 += carry0; h0 -= carry0 << 26;
    int64_t carry1 = (h1 + (1L << 24)) >> 25; h2 += carry1; h1 -= carry1 << 25;
    int64_t carry2 = (h2 + (1L << 25)) >> 26; h3 += carry2; h2 -= carry2 << 26;
    int64_t carry3 = (h3 + (int64_t)(1L << 24)) >> 25; h4 += carry3; h3 -= carry3 << 25; 

   //........modifying similar codes........//
   
    carry9 = (h9 + (1L << 24)) >> 25; h0 += carry9 * 19; h9 -= carry9 * (1L << 25);

    carry0 = ((h0 += (carry9 = (h9 + (int64_t)1 << 24) >> 25) * 19) + (1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 << 26;

    // Note: having combined last carry0 assignment with previous line > re-utilization AND enhancing calculation speed

    h[0] = (int32_t) h0; h[1] = (int32_t) h1; h[2] = (int32_t) h2;
    h[3] = (int32_t) h3; h[4] = (int32_t) h4; h[5] = (int32_t) h5;
    h[6] = (int32_t) h6; h[7] = (int32_t) h7; h[8] = (int32_t) h8;
    h[9] = (int32_t) h9;
}
// End of Code