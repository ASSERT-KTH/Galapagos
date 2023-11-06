fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t t_r0, t_r1, t_r2, t_r3, t_r4;
    uint128_t t_f0, t_f1, t_f2, t_f3, t_f4;
    uint128_t tf1_19, tf2_19, tf3_19, tf4_19;
    uint128_t tg0, tg1, tg2, tg3, tg4;
    uint64_t  tr00, tr01, tr02, tr03, tr04;
    uint64_t  new_carry;

    t_f0 = (uint128_t) f[0];
    t_f1 = (uint128_t) f[1];
    t_f2 = (uint128_t) f[2];
    t_f3 = (uint128_t) f[3];
    t_f4 = (uint128_t) f[4];

    tg0 = (uint128_t) g[0];
    tg1 = (uint128_t) g[1];
    tg2 = (uint128_t) g[2];
    tg3 = (uint128_t) g[3];
    tg4 = (uint128_t) g[4];

    tf1_19 = 19ULL * t_f1;
    tf2_19 = 19ULL * t_f2;
    tf3_19 = 19ULL * t_f3;
    tf4_19 = 19ULL * t_f4;

    t_r0 = t_f0 * tg0 + tf1_19 * tg4 + tf2_19 * tg3 + tf3_19 * tg2 + tf4_19 * tg1;
    t_r1 = t_f0 * tg1 +    t_f1 * tg0 + tf2_19 * tg4 + tf3_19 * tg3 + tf4_19 * tg2;
    t_r2 = t_f0 * tg2 +    t_f1 * tg1 +    t_f2 * tg0 + tf3_19 * tg4 + tf4_19 * tg3;
    t_r3 = t_f0 * tg3 +    t_f1 * tg2 +    t_f2 * tg1 +    t_f3 * tg0 + tf4_19 * tg4;
    t_r4 = t_f0 * tg4 +    t_f1 * tg3 +    t_f2 * tg2 +    t_f3 * tg1 +    t_f4 * tg0;

    tr00    = ((uint64_t) t_r0) & mask;
    new_carry  = (uint64_t) (t_r0 >> 51);
    t_r1    += new_carry;
    tr01    = ((uint64_t) t_r1) & mask;
    new_carry  = (uint64_t) (t_r1 >> 51);
    t_r2    += new_carry;
    tr02    = ((uint64_t) t_r2) & mask;
    new_carry  = (uint64_t) (t_r2 >> 51);
    t_r3    += new_carry;
    tr03    = ((uint64_t) t_r3) & mask;
    new_carry  = (uint64_t) (t_r3 >> 51);
    t_r4    += new_carry;
    tr04    = ((uint64_t) t_r4) & mask;
    new_carry  = (uint64_t) (t_r4 >> 51);
    tr00   += 19ULL * new_carry;
    new_carry  = tr00 >> 51;
    tr00   &= mask;
    tr01   += new_carry;
    new_carry  = tr01 >> 51;
    tr01   &= mask;
    tr02   += new_carry;

    h[0] = tr00;
    h[1] = tr01;
    h[2] = tr02;
    h[3] = tr03;
    h[4] = tr04;
}