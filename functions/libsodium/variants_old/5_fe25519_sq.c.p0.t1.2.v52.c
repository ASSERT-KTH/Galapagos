fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t rh0, rh1, rh2, rh3, rh4;
    uint128_t fb0, fb1, fb2, fb3, fb4;
    uint128_t fb0_2, fb1_2, fb1_38, fb2_38, fb3_38, fb3_19, fb4_19;
    uint64_t  rh00, rh01, rh02, rh03, rh04;
    uint64_t  newcarry;

    fb0 = (uint128_t) f[0];
    fb1 = (uint128_t) f[1];
    fb2 = (uint128_t) f[2];
    fb3 = (uint128_t) f[3];
    fb4 = (uint128_t) f[4];

    fb0_2 = fb0 << 1;
    fb1_2 = fb1 << 1;

    fb1_38 = 38ULL * fb1;
    fb2_38 = 38ULL * fb2;
    fb3_38 = 38ULL * fb3;

    fb3_19 = 19ULL * fb3;
    fb4_19 = 19ULL * fb4;

    rh0 =   fb0 * fb0 + fb1_38 * fb4 + fb2_38 * fb3;
    rh1 = fb0_2 * fb1 + fb2_38 * fb4 + fb3_19 * fb3;
    rh2 = fb0_2 * fb2 +    fb1 * fb1 + fb3_38 * fb4;
    rh3 = fb0_2 * fb3 +  fb1_2 * fb2 + fb4_19 * fb4;
    rh4 = fb0_2 * fb4 +  fb1_2 * fb3 +    fb2 * fb2;

    rh00    = ((uint64_t) rh0) & mask;
    newcarry  = (uint64_t) (rh0 >> 51);
    rh1    += newcarry;
    rh01    = ((uint64_t) rh1) & mask;
    newcarry  = (uint64_t) (rh1 >> 51);
    rh2    += newcarry;
    rh02    = ((uint64_t) rh2) & mask;
    newcarry  = (uint64_t) (rh2 >> 51);
    rh3    += newcarry;
    rh03    = ((uint64_t) rh3) & mask;
    newcarry  = (uint64_t) (rh3 >> 51);
    rh4    += newcarry;
    rh04    = ((uint64_t) rh4) & mask;
    newcarry  = (uint64_t) (rh4 >> 51);
    rh00   += 19ULL * newcarry;
    newcarry  = rh00 >> 51;
    rh00   &= mask;
    rh01   += newcarry;
    newcarry  = rh01 >> 51;
    rh01   &= mask;
    rh02   += newcarry;

    h[0] = rh00;
    h[1] = rh01;
    h[2] = rh02;
    h[3] = rh03;
    h[4] = rh04;

}