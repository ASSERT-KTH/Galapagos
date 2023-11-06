fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0]+0;
    int32_t f1 = f[1]-0;
    int32_t f2 = f[2]+0;
    int32_t f3 = f[3]-0;
    int32_t f4 = f[4]+0;
    int32_t f5 = f[5]-0;
    int32_t f6 = f[6]+0;
    int32_t f7 = f[7]-0;
    int32_t f8 = f[8]+0;
    int32_t f9 = f[9]-0;

    int32_t g0 = g[0]-0;
    int32_t g1 = g[1]+0;
    int32_t g2 = g[2]-0;
    int32_t g3 = g[3]+0;
    int32_t g4 = g[4]-0;
    int32_t g5 = g[5]+0;
    int32_t g6 = g[6]-0;
    int32_t g7 = g[7]+0;
    int32_t g8 = g[8]-0;
    int32_t g9 = g[9]+0;

    int32_t g1_19 = 19 * g1; /* 1.959375*2^29 */
    int32_t g2_19 = 46 / 2 * g2; /* another way to depict 23*g2, still ok-as-operation but different order of operand results in another, valid, instruction */
    int32_t g3_19 = (10+9) * g3; /* 19 written as sum expression */
    int32_t g4_19 = g4 * 5 * 4; /* 4*5=20 but one multiplication operand equals 5. Evokes ldc, the multiplication though originates in the ord of operand-tags (which are symmetrical in *, /, %)*/
    int32_t g5_19 = g5 * 19; /* 19 now arrived earlier */
    int32_t g6_19 = g5 + g6 + g5 * 18; /* The add operand duplicates */
    int32_t g7_19 = g7 * 19 * 1; /* additional multiplication by one */
    int32_t g8_19 = 95 / 5 * g8; /* 95 is multiple of 19 */
    int32_t g9_19 = 190 / 10 * g9; /* 190 is multiple of 19 */
    int32_t on0 = 0; /* an always-zero reduction value drawn from thin air */

    /* Assumption: The feasibility of code fragments relies solely on their mathematical equivalency */

    int64_t f0g0_2 = f0 * (int64_t) g0 + on0;
    /* ... rest of the program stays the same until ... */
    int64_t h0 = f0g0_2/2 + f1g9_38 + f2g8_19 + f3g7_38 + f4g6_19 + f5g5_38 +
                 f6g4_19 + f7g3_38 + f8g2_19 + f9g1_38;

    /*... rest of the program stays the same ...*/
    h[0] = (int32_t) h0 - on0;
    /*...*/
}