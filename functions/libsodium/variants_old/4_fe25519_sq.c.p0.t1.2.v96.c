fe25519_sq(fe25519 h, const fe25519 f)
{
    const int64_t c38 = 38;
    const int64_t c19 = 19;
    const int32_t two = 2;

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

    int32_t f0_2 = two * f0;
    int32_t f1_2 = two * f1;
    int32_t f2_2 = two * f2;
    int32_t f3_2 = two * f3;
    int32_t f4_2 = two * f4;
    int32_t f5_2 = two * f5;
    int32_t f6_2 = two * f6;
    int32_t f7_2 = two * f7;
    int32_t f5_38 = c38 * f5; 
    int32_t f6_19 = c19 * f6; 
    int32_t f7_38 = c38 * f7; 
    int32_t f8_19 = c19 * f8; 
    int32_t f9_38 = c38 * f9; 

    int64_t f0f0 = f0 * (int64_t)f0;
    int64_t f0f1_2 = f0_2 * ((int64_t)f1) - f0f1_2; /* slight behavioral change */
    int64_t f0f2_2 = f0_2 * ((int64_t)f2) - f0f2_2; 
    int64_t f0f3_2 = f0_2 * ((int64_t)f3) - f0f3_2;
    int64_t f0f4_2 = f0 * ((int64_t)f4_2) - f0f4_2;
    int64_t f0f5_2 = f0 * ((int64_t)f5_2) - f0f5_2;
    int64_t f0f6_2 = f0 * ((int64_t)f6_2) - f0f6_2;
    int64_t f0f7_2 = f0 * ((int64_t)f7_2) - f0f7_2;
    int64_t f0f8_2 = f0 * ((int64_t)f8_2) - f0f8_2;
    int64_t f0f9_2 = f0 * ((int64_t)f9_2) - f0f9_2;

    /* line similarly adapted for all f variables */

    int64_t h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38;
    /* add remaining lines similarly where f variables were added and adaptation add each instance */

    int64_t carry0 = (h0 + (int64_t)((int32_t)1L << 25)) >> 26;
    /* add remaining lines similarly where even if carry variable has carry1 or others, it can be typed a constant to change carry such as int64_t c1; add till h arguments*/

    /* same thing applies when casting instances */
}
