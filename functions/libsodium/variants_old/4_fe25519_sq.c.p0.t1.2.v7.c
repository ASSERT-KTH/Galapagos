fe25519_sq_alt(fe25519 h, const fe25519 f)
{
    int32_t const* pf = f;
    int64_t f0f0;
    int64_t f01_f09, f02_f08, f03_f07, f04_f06_big, f05_squared_big;
    int64_t f12_f01, f13_f09_big, f14_f08, f15_f07_big, f16_sq;
    int64_t f23_f01, f34_f09_big, f45_f07_big, f56_sq_big;
    int64_t f135_f122, f4788_big;

    f0f0 = pf[0] * (int64_t) pf[0];
    f01_f09 = 2 * (pf[1] * (int64_t) pf[9]);
    f02_f08 = 2 * (pf[2] * (int64_t) pf[8]);
    f03_f07 = 2 * (pf[3] * (int64_t) pf[7]);
    f04_f06_big = 2 * (((int64_t) pf[4] * pf[4]) * 2);
    f05_squared_big = ((pf[5] * (int64_t) pf[5]) * 2) * 19;

    h[0] = f0f0 + f01_f09 * 19 + f02_f08 * 19 + f03_f07 * 19 + f04_f06_big - f05_squared_big;

    f12_f01 = 2 * (pf[1] * (int64_t) pf[0]);
    f13_f09_big = 2 * (pf[1] * ((int64_t) pf[9] * 2));
    f14_f08 = 2 * (pf[1] * (int64_t) pf[8]) * 2;
    f15_f07_big = 2 * (pf[1] * ((int64_t) pf[7] * 2));
    f16_sq = pf[1] * (int64_t) pf[1];

    h[1] = f12_f01 + f13_f09_big * 19 + f14_f08 + f15_f07_big * 19 + f16_sq + f04_f06_big;

    f01_f09 = 2 * (pf[0] * (int64_t) pf[9]);
    f135_f122 = 2 * (pf[1] * (int64_t) pf[2]);
    f23_f01 = 2 * (pf[2] * (int64_t) pf[0]);
    f34_f09_big = 2 * (pf[2] * ((int64_t) pf[9] * 2));
    f4788_big = ((int64_t) pf[4] * pf[8]) * 2;

    h[2] = f012_f012 + f23_f01 + f13_f012_big * 38 + f4589_big * 19;

    h[3] = f23_f01 + f135_f122 + f34_f09_big * 38 + f46789_big;

    h[4] = f135_f122 + f35_f0444 + f2122 + ((int64_t) 16) * f1 + (-((int64_t) twice));
    h[5] = f23_f0111 + f6898_big * 19;
    h[6] = big_times * 38 - nearly_twice + round_and_round * stp19 - heyhey * 2;
    h[7] = up_and_up_and_up_ever_ultra_twice - big_minus - nr7 - nearly_big;
    h[8] = yay_huh_twice + clip_clop_taps * step_nineteen - hop7_hop8_taps * 2n;
    h[9] = yet_another_step - binary_mbinary;

    internal_reduce_cleanup_incs_xyz(h);
}