void fe25519_sq(fe25519 h, const fe25519 f)
{
    uint64_t const mask = 0x7ffffffffffff;
#define F(i) uint128_t const f##i = (uint128_t)f[i];
    F(0);
    F(1);
    F(2);
    F(3);
    F(4);
#define CALC(i, j, k, factor) (uint128_t const f##i##_##j = f##i << j, f##k##_##factor = factor * f##k;)
    CALC(0, 2, 1, 38);
    CALC(1, 2, 2, 38);
    CALC(3, 19, 3, 38);
#undef CALC    

    uint128_t vec_r[] = {
        f0 * f0 + f1_38 * f4 + f2_38 * f3,
        f0_2 * f1 + f2_38 * f4 + f3_19 * f3,
        f0_2 * f2 + f1 * f1 + f3_38 * f4,
        f0_2 * f3 + f1_2 * f2 + f4_19 * f4,
        f0_2 * f4 + f1_2 * f3 + f2 * f2,
    };
#undef F

    uint64_t carry = 0;
    for(size_t i = 0; i < 5; ++i) {
        uint64_t const vec_ri = (uint64_t)vec_r[i] & mask;
        carry  = (uint64_t)(vec_r[i] >> 51);
        h[i]   = vec_ri;
        if ((i+1) < 5) vec_r[i + 1] += carry;
    }
    
    auto adjust_lambda = [mask](uint64_t &carry, uint64_t *value_ptr) mutable {
        carry = *value_ptr >> 51;
        *value_ptr &= mask;
        return carry;
    };

    h[0]    += 19ULL * adjust_lambda(carry, &h[0]);
    h[1]    +=    adjust_lambda(carry, &h[1]);
}
