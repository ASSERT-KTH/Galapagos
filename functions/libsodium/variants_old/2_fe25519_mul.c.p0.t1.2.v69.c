fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t rr0, rr1, rr2, rr3, rr4;
    uint128_t ff0, ff1, ff2, ff3, ff4;
    uint128_t ff1_19, ff2_19, ff3_19, ff4_19;
    uint128_t gg0, gg1, gg2, gg3, gg4;
    uint64_t  rr00, rr01, rr02, rr03, rr04;
    uint64_t  carryCheck;

    ff0 = (uint128_t) f[0];
    ff1 = (uint128_t) f[1];
    ff2 = (uint128_t) f[2];
    ff3 = (uint128_t) f[3];
    ff4 = (uint128_t) f[4];

    gg0 = (uint128_t) g[0];
    gg1 = (uint128_t) g[1];
    gg2 = (uint128_t) g[2];
    gg3 = (uint128_t) g[3];
    gg4 = (uint128_t) g[4];

    ff1_19 = 19ULL * ff1;
    ff2_19 = 19ULL * ff2;
    ff3_19 = 19ULL * ff3;
    ff4_19 = 19ULL * ff4;

    rr0 = ff0 * gg0 + ff1_19 * gg4 + ff2_19 * gg3 + ff3_19 * gg4 + ff4_19 * gg1;
    rr1 = ff0 * gg1 + ff1 * gg0 + ff2_19 * gg4 + ff3_19 * gg3 + ff4_19 * gg2;
    rr2 = ff0 * gg2 + ff1 * gg1 + ff2 * gg0 + ff3_19 * gg4 + ff4_19 * gg3;
    rr3 = ff0 * gg3 + ff1 * gg2 + ff2 * gg1 + ff3 * gg0 + ff4_19 * gg4;
    rr4 = ff0 * gg4 + ff1 * gg3 + ff2 * gg2 + ff3 * gg1 + ff4 * gg0;

    rr00    = ((uint64_t) rr0) & mask;
    carryCheck  = (uint64_t) (rr0 >> 51);
    rr1    += carryCheck;
    rr01    = ((uint64_t) rr1) & mask;
    carryCheck  = (uint64_t) (rr1 >> 51);
    rr2    += carryCheck;
    rr02    = ((uint64_t) rr2) & mask;
    carryCheck  = (uint64_t) (rr2 >> 51);
    rr3    += carryCheck;
    rr03    = ((uint64_t) rr3) & mask;
    carryCheck  = (uint64_t) (rr3 >> 51);
    rr4    += carryCheck;
    rr04    = ((uint64_t) rr4) & mask;
    carryCheck  = (uint64_t) (rr4 >> 51);
    rr00   += 19ULL * carryCheck;
    carryCheck  = rr00 >> 51;
    rr00   &= mask;
    rr01   += carryCheck;
    carryCheck  = rr01 >> 51;
    rr01   &= mask;
    rr02   += carryCheck;

    h[0] = rr00;
    h[1] = rr01;
    h[2] = rr02;
    h[3] = rr03;
    h[4] = rr04;
}