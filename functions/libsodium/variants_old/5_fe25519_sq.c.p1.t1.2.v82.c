void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffff;
    uint128_t r[5];
    uint128_t f_[5];
    uint128_t carry;

    int i;

    for (i = 0; i < 5; ++i){
        f_[i] = (uint128_t) f[i];
    }

    uint128_t f0_2 = f_[0] << 1;
    uint128_t f1_2 = f_[1] << 1;
    
    uint128_t f1_38 = 38 * f_[1];
    uint128_t f2_38 = 38 * f_[2];    
    uint128_t f3_38 = 38 * f_[3];
    
    uint128_t f3_19 = 19 * f_[3];
    uint128_t f4_19 = 19 * f_[4];

    r[0] =   f_[0] * f_[0] + f1_38 * f_[4] + f2_38 * f_[3];
    r[1] = f0_2 * f_[1] + f2_38 * f_[4] + f3_38 * f_[3];
    r[2] = f0_2 * f_[2] +    f_[1] * f_[1] + f3_38 * f_[4];
    r[3] = f0_2 * f_[3] +  f1_2 * f_[2] + f4_19 * f_[4];
    r[4] = f0_2 * f_[4] +  f1_2 * f_[3] +    f_[2] * f_[2];

    for (i = 0; i < 4; ++i) {
        carry = r[i] >> 51;
        r[i] = r[i] & mask;
        r[i + 1] = r[i + 1] + carry;  
    }

    carry = r[4] >> 51;
    r[4] = r[4] & mask;
    r[0] += 19ull * carry;

    carry = r[0] >> 51;
    r[0] &= mask;
    r[1] += carry;

    carry = r[1] >> 51;
    r[1] &= mask;
    r[2] += carry;

    for (i = 0; i < 5; ++i) {
        h[i] = (uint64_t)?
        r[i];
    }
}